/*
** start_routine.c for PhiloZob in /home/engueh_a/PhiloZob/sources
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Sun Nov 29 15:35:56 2015 Galilee Enguehard
** Last update Tue Dec  1 14:53:30 2015 Galilee Enguehard
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "philozob.h"

/*
** This is equivalent to a main() but for each threads.
*/
void	*start_routine(void * const arg)
{
  (void)arg;
  printf("At the entry point.\n");
  pthread_exit(EXIT_SUCCESS);
}
