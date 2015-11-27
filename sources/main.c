/*
** main.c for PhiloZob in /home/engueh_a/PhiloZob
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Nov 25 11:09:47 2015 Galilee Enguehard
** Last update Fri Nov 27 10:37:54 2015 Galilee Enguehard
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int		main(const int ac, char * const av[])
{
  t_control	control = 0;
  int		i = 0;
  pthread_t	thread_tab[NB_PHIL] = {0};

  if (create_threads(&control) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (assign_thread(&control, &thread_tab) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  /*
  ** Pthread Join tout les threads a la fin sinon on a un probleme.
  */
  return (EXIT_SUCCESS);
}
