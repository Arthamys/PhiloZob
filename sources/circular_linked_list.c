/*
** circular_linked_list.c for PhiloZob in /home/engueh_a/PhiloZob/sources
**
** Made by Galilee Enguehard
** Login   <engueh_a@epitech.net>
**
** Started on  Wed Nov 25 14:16:46 2015 Galilee Enguehard
** Last update Thu Nov 26 16:11:20 2015 Galilee Enguehard
*/

#include <stdlib.h>
#include "philozob.h"

static void	init_node(t_threads *node)
{
  node->left = NULL;
  node->right = NULL;
  node->rice_left = RICE_GRAINS;
  node->state = RESTING;
  node->chop = AVAILABLE;
}

int		create_first_node(t_control *ctrl)
{
  t_threads	*new;

  if ((ctrl = malloc(sizeof(t_control))) == NULL ||
      ((new = malloc(sizeof(t_threads))) == NULL))
    return (EXIT_FAILURE);
  init_node(new);
  ctrl->head = new;
  ctrl->tail = new;
  return (EXIT_SUCCESS);
}

int		add_right_node(t_control *ctrl)
{
  t_threads	*new;

  if ((new = malloc(sizeof(t_threads))) == NULL)
    return (EXIT_FAILURE);
  init_node(new);
  new->left = ctrl->tail;
  new->right = ctrl->head;
  ctrl->tail->right = new;
  ctrl->tail = new;
  ctrl->head->left = ctrl->tail;
  return (EXIT_SUCCESS);
}
