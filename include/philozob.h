/*
** philozob.h for PhiloZob in /home/engueh_a/PhiloZob
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Nov 25 11:15:30 2015 Galilee Enguehard
** Last update Thu Dec  3 14:18:24 2015 Galilee Enguehard
*/

#ifndef PHILOZOB_H_
# define PHILOZOB_H_

# define NB_PHIL		7
# define EAT_TIME		7000
# define THINK_TIME		10000
# define RICE_GRAINS		100
# define LOW_ID(x, y)		(x) > (y) ? (y) : (x)
# define ERROR_MALLOC		"Could not allocate memory.\n"
# define ERROR_CR_THREAD	"Could not create thread.\n"
# define EROOR_MUTEX_XLOCK1	"There was an error "
# define ERROR_MUTEX_XLOCK2	"in a mutex locking/unlocking operation."

typedef enum		e_state
  {
    RESTING = 0,
    EATING,
    THINKING
  }			t_state;

typedef enum		e_chop_state
  {
    DIRTY = 0,
    CLEAN
  }			t_chop_state;

typedef enum		e_chop
  {
    AVAILABLE = 0,
    UNAVAILABLE
  }			t_chop;

typedef struct		s_threads
{
  struct s_threads	*left;
  void			*thread; //pthread_t *
  void			*chop_mutex; //pthread_mutex_t *
  int			th_id;
  t_chop		chop;
  t_chop_state		chop_state;
  t_state		state;
  int			rice_left;
  struct s_threads	*right;
}			t_threads;

typedef struct		s_control
{
  t_threads		*head;
  t_threads		*tail;
}			t_control;

int		create_threads(t_control **);
int		assign_thread(t_control * const, pthread_t *);
int		add_right_node(t_control * const);
int		create_first_node(t_control **);
void		free_linked_list(t_control *);
void		*start_routine(void *);
int		thread_init(t_control * const);

#endif /* !PHILOZOB_H_ */
