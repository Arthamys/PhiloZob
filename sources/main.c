/*
** main.c for PhiloZob in /home/engueh_a/PhiloZob
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Nov 25 11:09:47 2015 Galilee Enguehard
** Last update Tue Dec  1 14:03:40 2015 Galilee Enguehard
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "philozob.h"

int		main(const int ac, char * const av[])
{
  t_control	*control;
  pthread_t	thread_tab[NB_PHIL] = {0};
  t_threads	*tmp;

  (void)ac;
  (void)av;
  control = NULL;
  if (create_threads(&control) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (assign_thread(control, thread_tab) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (thread_init(control) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  tmp = control->head;
  while (tmp != control->tail)
    {
      pthread_join(*(pthread_t *)tmp->thread, NULL);
      tmp = tmp->right;
    }
  free_linked_list(control);
  return (EXIT_SUCCESS);
}
