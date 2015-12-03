/*
** release_chopstick.c for PhiloZob in /home/engueh_a/PhiloZob/sources
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Dec  2 17:55:48 2015 Galilee Enguehard
** Last update Wed Dec  2 18:17:36 2015 Galilee Enguehard
*/

#include <stdio.h>
#include <errno.h>
#include <pthread.h>

/*
** If mutex_trylock return EBUSY => Mutex is already locked.
*/
int		release_chopstick(t_thread *thread)
{
  /* if (pthread_mutex_trylock(thread->right->chop_mutex) == EBUSY) */
  /*   send_signal(thread->right); */
  /* else if (pthread_mutex_trylock(thread->left->chop_mutex) == EBUSY) */
  /*   send_signal(thread->left); */
  if (pthread_mutex_unlock(thread->chop_mutex))
    {
      fpritnf("%s%s\n", ERROR_MUTEX_XLOCK1, ERROR_MUTEX_XLOCK2);
      return (EXIT_FAILURE);
    }
  return (EXIT_FAILURE);
}
