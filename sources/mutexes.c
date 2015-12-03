/*
** mutexes.c for PhiloZob in /home/engueh_a/PhiloZob/sources
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Dec  2 12:46:58 2015 Galilee Enguehard
** Last update Wed Dec  2 17:54:35 2015 Galilee Enguehard
*/

#include <unistd.h>
#include <pthread.h>
#include "philozob.h"

pthread_mutex_t	fork_mutex[NB_PHIL];

int		initialize_mutexes()
{
  int		i;

  i = 0;
  while (i < NB_PHIL)
    {
      fork_mutex[i] = PTHREAD_MUTEX_INITIALIZER;
      ++i;
    }
  return (EXIT_SUCCESS);
}

/*
** In the algorithm function, I will define the way all the different threads
** will act, that is, when will they eat, resst, think. This will be organized
** with a little bit of randomness to it, since a philosopher can go through
** either of two states after resting. So I will try to mix things up a bit
** after a resting state so all threads don't follow exactly the same path.
*/
int		algorithm(t_control *ctrl)
{
  t_threads	*tmp;
  int		i;

  i = 0;
  tmp = ctrl->head;
  while (i < NB_PHIL)
    {
      start_eating();

    }
}
