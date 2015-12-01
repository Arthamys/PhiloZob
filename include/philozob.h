/*
** philozob.h for PhiloZob in /home/engueh_a/PhiloZob
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Nov 25 11:15:30 2015 Galilee Enguehard
** Last update Tue Dec  1 16:29:23 2015 Galilee Enguehard
*/

#ifndef PHILOZOB_H_
# define PHILOZOB_H_

# define NB_PHIL		7
# define EAT_TIME		7000
# define THINK_TIME		10000
# define RICE_GRAINS		100
# define ERROR_MALLOC		"Could not allocate memory.\n"
# define ERROR_CR_THREAD	"Could not create thread.\n"

typedef enum		e_state
  {
    RESTING = 0,
    EATING,
    THINKING
  }			t_state;

typedef enum		e_chop_state
  {
    AVAILABLE = 0,
    UNAVAILABLE
  }			t_chop_state;

typedef struct		s_threads
{
  struct s_threads	*left;
  void			*thread; //pthread_t *
  int			th_id;
  t_chop_state		chop;
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
