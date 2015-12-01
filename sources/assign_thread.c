/*
** assign_thread.c for PiloZob in /home/engueh_a/PhiloZob/sources
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Fri Nov 27 10:30:54 2015 Galilee Enguehard
** Last update Tue Dec  1 14:22:31 2015 Galilee Enguehard
*/

#include <pthread.h>
#include <stdlib.h>
#include "philozob.h"

int		assign_thread(t_control * const ctrl,
			      pthread_t *thread_tab)
{
  int		i = 0;
  t_threads	*tmp;

  tmp = ctrl->head;
  while (i < NB_PHIL)
    {
      tmp->th_id = i;
      tmp->thread = &thread_tab[i];
      ++i;
      tmp = tmp->right;
    }
  return (EXIT_SUCCESS);
}
