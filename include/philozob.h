/*
** philozob.h for PhiloZob in /home/engueh_a/PhiloZob
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Nov 25 11:15:30 2015 Galilee Enguehard
** Last update Thu Dec 31 05:23:33 2015 Galilee Enguehard
*/

#ifndef PHILOZOB_H_
# define PHILOZOB_H_

#include <semaphore.h>
#include <pthread.h>

# define LEFT			0
# define RIGHT			1
# define NB_PHIL		5
# define EAT_TIME		4
# define INTERLUDE		1
# define SPAGHETTI		120
# define HUNGRY_TIME		2
# define ERROR_MALLOC		"Could not allocate memory.\n"
# define ERROR_SEM_GET		"Could not get semaphore value.\n"
# define ERROR_SEM_INIT		"Could not initialize semaphore.\n"
# define ERROR_SEM_WAIT		"There was an error in the sem_wait function.\n"
# define ERROR_SEM_DEST		"Could not destroy semaphore.\n"
# define ERROR_SEM_POST		"Could not decrement the semaphore counter.\n"
# define ERROR_NULL_PTR		"Recieved a NULL pointer in function :"
# define ERROR_CR_THREAD	"Could not create thread.\n"
# define ERROR_JN_THREAD	"Could not join threads.\n"

typedef enum		e_state
  {
    SLEEPING = 0,
    EATING,
    HUNGRY
  }			t_state;

typedef enum		e_fork
  {
    AVAILABLE = 0,
    UNAVAILABLE
  }			t_fork;

typedef struct		s_philo
{
  int			id;
  t_fork		fork;
  t_state		state;
  sem_t			fork_s;
  pthread_t		thread;
  struct s_philo	*next;
  int			spaghetti;
}			t_philo;

void			you_eat(t_philo *);
void			you_sleep(t_philo *);
void			be_hungry(t_philo *);
void			*display_thread_states(void *);
void			*start_routine(void *);

#endif /* !PHILOZOB_H_ */
