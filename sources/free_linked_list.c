/*
** free_linked_list.c for PhiloZob in /home/engueh_a/PhiloZob
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Mon Nov 30 17:49:58 2015 Galilee Enguehard
** Last update Tue Dec  1 14:23:36 2015 Galilee Enguehard
*/

#include <stdlib.h>
#include <stdio.h>
#include "philozob.h"

void		free_linked_list(t_control *control)
{
  t_threads	*tmp;
  t_threads	*to_free;
  int		i = 0;

  tmp = control->head;
  to_free = NULL;
  while (i < NB_PHIL)
    {
      to_free = tmp;
      tmp = tmp->right;
      free(to_free);
      to_free = NULL;
      ++i;
    }
  free(to_free);
  free(control);
}
