/*
** start_routine.c for PhiloZob in /home/engueh_a/PhiloZob/sources
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Sun Nov 29 15:35:56 2015 Galilee Enguehard
** Last update Thu Dec  3 17:47:24 2015 Galilee Enguehard
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "philozob.h"

/*
** 1) For every pair of philosophers contending for a resource, create
** a fork and give it to the philosopher with the lower ID (n for
** agent Pn). Each fork can either be dirty or clean. Initially, all
** forks are dirty.
**
** 2) When a philosopher wants to use a set of
** resources (i.e. eat), he must obtain the forks from his contending
** neighbors. For all such forks he does not have, he sends a request
** message.
**
** 3) When a philosopher with a fork receives a request
** message, he keeps the fork if it is clean, but gives it up when it
** is dirty. If he sends the fork over, he cleans the fork before
** doing so.
**
** 4) After a philosopher is done eating, all his forks
** become dirty. If another philosopher had previously requested one
** of the forks, he cleans the fork and sends it.
*/
void		*start_routine(void * const arg)
{
  t_threads	*phil;

  phil = arg;
  while (phil->rice_left)
    {
      printf("Philosopher %d has rice grains left => %d.\n", phil->th_id, phil->rice_left);
      --phil->rice_left;
    }
  pthread_exit(EXIT_SUCCESS);
}
