/*
** create_threads.c for PhiloZob in /home/engueh_a/PhiloZob
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Nov 25 11:13:58 2015 Galilee Enguehard
** Last update Tue Dec  1 14:25:08 2015 Galilee Enguehard
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "philozob.h"

int		thread_init(t_control * const control)
{
  t_threads	*tmp = control->head;
  int		i = 0;

  while (i < NB_PHIL)
    {
      if (pthread_create((pthread_t *)tmp->thread, NULL, start_routine,
			 (void *)control))
	return (EXIT_FAILURE);
      tmp = tmp->right;
      ++i;
    }
  return (EXIT_SUCCESS);
}

int		create_threads(t_control **control)
{
  int		i = 0;

  while (i < NB_PHIL)
    {
      if (!(*control))
	{
	  if (create_first_node(control) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
      else if (add_right_node((*control)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      ++i;
    }
  return (EXIT_SUCCESS);
}
