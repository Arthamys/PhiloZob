/*
** display.c for PhiloZob in /home/engueh_a/PhiloZob/sources
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Dec 30 23:51:29 2015 Galilee Enguehard
** Last update Thu Dec 31 05:13:51 2015 Galilee Enguehard
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "philozob.h"

static int	all_have_spaghetti(t_philo *phil_array)
{
  t_philo	*tmp;
  int		i;

  tmp = phil_array;
  i = 0;
  while (i < NB_PHIL)
    {
      if (tmp->spaghetti <= 0)
	return (0);
      tmp = tmp->next;
      ++i;
    }
  return (1);
}

static void	print_state(t_philo *philo)
{
  if (philo->state == SLEEPING)
    printf("Philosopher #%d is sleeping...\n", philo->id);
  else if (philo->state == HUNGRY)
    printf("Philosopher #%d wants to eat...\n", philo->id);
  else
    printf("Philosopher #%d is eating...\n", philo->id);
}

void		*display_thread_states(void *philosopher_array)
{
  t_philo	*tmp;;
  int		i;

  while (all_have_spaghetti(philosopher_array))
    {
      i = 0;
      tmp = (t_philo *)philosopher_array;
      while (i < NB_PHIL)
	{
	  print_state(tmp);
	  ++i;
	  tmp = tmp->next;
	}
      sleep(INTERLUDE);
      system("clear");
    }
  return (NULL);
}
