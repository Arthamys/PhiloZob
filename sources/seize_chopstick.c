/*
** seize_chopstick.c for PhiloZob in /home/engueh_a/PhiloZob/sources
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Dec  2 18:37:53 2015 Galilee Enguehard
** Last update Wed Dec  2 19:03:20 2015 Galilee Enguehard
*/

#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include "philozob.h"

int		seize_chopstick(t_threads *thread)
{
  if (pthread_mutex_trylock(thread) == EBUSY && thread->left->state == THINKING)
    request_chop(thread->left);
  else if (pthread_mutex_trylock(thread->right) == EBUSY && thread->right->state == THINKING)
    request_chop(thread->right);
  thread->chop = UNAVAILABLE;
  thread->right->chop = UNAVAILABLE;
  return (EXIT_SUCCESS);
}
