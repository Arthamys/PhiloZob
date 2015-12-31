/*
** main.c for PhiloZob in /home/engueh_a/PhiloZob/sources
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Dec 30 17:22:46 2015 Galilee Enguehard
** Last update Thu Dec 31 05:24:19 2015 Galilee Enguehard
*/

#include <stdio.h>
#include <stdlib.h>
#include "philozob.h"

void		*start_routine(void *philosophe)
{
  t_philo	*philo;
  int		forks[2];

  philo = (t_philo *)philosophe;
  while (philo->spaghetti)
    {
      sem_getvalue(&philo->fork_s, &forks[LEFT]);
      sem_getvalue(&philo->next->fork_s, &forks[RIGHT]);
      if (forks[LEFT] && forks[RIGHT])
	you_eat(philo);
      else if (forks[LEFT] && !forks[RIGHT])
	be_hungry(philo);
      else
	you_sleep(philo);
    }
  return (NULL);
}

static int	init_thread(t_philo phil_array[NB_PHIL])
{
  int		i;
  pthread_t	display_thread;

  i = 0;
  if (pthread_create(&display_thread, NULL, display_thread_states, phil_array))
    return (fprintf(stderr, "%s\n", ERROR_CR_THREAD));
  while (i < NB_PHIL)
    {
      if (pthread_create(&phil_array[i].thread, NULL, start_routine, &phil_array[i]))
	return (fprintf(stderr, "%s\n", ERROR_CR_THREAD));
      ++i;
    }
  if (pthread_join(display_thread, NULL))
    return (fprintf(stderr, "%s\n", ERROR_JN_THREAD));
  return (EXIT_SUCCESS);
}

static int	init_array(t_philo *phil_array)
{
  int		i;

  i = 0;
  while (i < NB_PHIL)
    {
      phil_array[i].id = i;
      phil_array[i].fork = AVAILABLE;
      phil_array[i].state = SLEEPING;
      phil_array[i].spaghetti = 900;
      if (i < (NB_PHIL - 1))
	phil_array[i].next = &phil_array[i + 1];
      else
	phil_array[i].next = &phil_array[0];
      if (sem_init(&phil_array[i].fork_s, 0, 1))
	return (fprintf(stderr, "%s\n", ERROR_SEM_INIT));
      ++i;
    }
  return (EXIT_SUCCESS);
}

int		main()
{
  t_philo	phil_array[NB_PHIL];
  int		i;

  i = 0;
  if (init_array(phil_array) != EXIT_SUCCESS)
    return (1);
  if (init_thread(phil_array) != EXIT_SUCCESS)
    return (1);
  while (i < NB_PHIL)
    {
      if (pthread_join((phil_array[i].thread), NULL))
	return (fprintf(stderr, "%s\n", ERROR_JN_THREAD));
      if (sem_destroy(&phil_array[i].fork_s))
	return (fprintf(stderr, "%s\n", ERROR_SEM_DEST));
    }
}
