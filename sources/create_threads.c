/*
** create_threads.c for PhiloZob in /home/engueh_a/PhiloZob
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Nov 25 11:13:58 2015 Galilee Enguehard
** Last update Fri Nov 27 10:39:56 2015 Galilee Enguehard
*/

#include <stdio.h>
#include <pthread.h>
#include "philozob.h"

static int	thread_init(t_control * const control)
{
  t_threads	*tmp;

  tmp = control->head;
  while (tmp != control->tail)
    {
    }
}

int		create_threads(t_ctrl * const control)
{
  int		i = 0;

  while (i < NB_PHIL)
    {
      if (!control)
	{
	  if (create_first_node(control) == EXIT_FAILURE)
	    {
	      fprintf(stderr, "%s\n", ERROR_MALLOC);
	      return (EXIT_FAILURE);
	    }
	}
      else if (add_right_node(control) == EXIT_FAILURE)
	{
	  fprintf(stderr, "%s\n", ERROR_MALLOC);
	  return (EXIT_FAILURE);
	}
      ++i;
    }
  if (thread_init(control) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
