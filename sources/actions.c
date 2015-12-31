/*
** actions.c for PhiloZob in /home/engueh_a/PhiloZob/sources
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Dec 30 20:27:57 2015 Galilee Enguehard
** Last update Thu Dec 31 05:22:12 2015 Galilee Enguehard
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "philozob.h"

static int	get_fork_val(t_philo *next_philo)
{
  int		sem_val;

  if (sem_getvalue(&next_philo->fork_s, &sem_val))
    {
      fprintf(stderr, "%s\n", ERROR_SEM_GET);
      return (0);
    }
  if (next_philo->fork == AVAILABLE && sem_val >= 1)
    return (1);
  return (0);
}

void		you_sleep(t_philo *philo)
{
  if (philo->state == EATING)
    {
      if (sem_post(&philo->fork_s) || sem_post(&philo->next->fork_s))
	{
	  fprintf(stderr, "%s\n", ERROR_SEM_POST);
	  exit(EXIT_FAILURE);
	}
      philo->fork = AVAILABLE;
      philo->next->fork = AVAILABLE;
      philo->state = SLEEPING;
    }
}

void		be_hungry(t_philo *philo)
{
  if (sem_wait(&philo->fork_s))
    {
      fprintf(stderr, "%s\n", ERROR_SEM_WAIT);
      exit(EXIT_FAILURE);
    }
  philo->state = HUNGRY;
  philo->fork = UNAVAILABLE;
  if (sem_post(&philo->fork_s))
    {
      fprintf(stderr, "%s\n", ERROR_SEM_POST);
      exit(EXIT_FAILURE);
    }
  sleep(HUNGRY_TIME);
  if (get_fork_val(philo->next))
    you_eat(philo);
  else
    start_routine(philo);
}

void		you_eat(t_philo *philo)
{
  if (sem_wait(&philo->fork_s) || sem_wait(&philo->next->fork_s))
    {
      fprintf(stderr, "%s\n", ERROR_SEM_WAIT);
      exit(EXIT_FAILURE);
    }
  philo->state = EATING;
  philo->fork = UNAVAILABLE;
  philo->next->fork = UNAVAILABLE;
  you_sleep(philo);
}
