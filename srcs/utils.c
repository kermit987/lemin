/*
** utils.c for lem in in /home/metz_a/rendu/CPE_2014_lemin
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Mon Apr 27 11:39:36 2015 Aurélien Metz
<<<<<<< HEAD
** Last update Sat May  2 17:48:34 2015 Steven Loo Fat
=======
** Last update Sat May  2 18:13:07 2015 Aurélien Metz
>>>>>>> e137b368e1fa66367be6c82acf1652ce633c3064
*/

#include "launch.h"

t_branch	*lightest(t_tree *tree)
{
  t_branch	*tmp_weight;
  unsigned int	i;

  i = 0;
  tmp_weight = &tree->branches[i];
  while (i < tree->nbr_branches)
    {
      if (tmp_weight->weight > tree->branches[i].weight)
	tmp_weight = &tree->branches[i];
      i++;
    }
  return (tmp_weight);
}

int		allowed(t_room *room, t_room **fr)
{
  unsigned int	i;

  i = 0;
  if (fr)
    while (fr[i])
      if (fr[i++] == room)
	return (0);
  return (1);
}

int		booked(t_ant *ant, t_room *room, unsigned int turn)
{
  unsigned int	i;

  if (room->e_next == NULL)
    return (0);
  i = 0;
  while (ant[i].path)
    if (ant[i++].path[turn - 1] == room)
      return (1 + booked(ant, room, turn + 1));
  return (0);
}

void		add(t_ant *ant, t_room *room, unsigned int turn)
{
  t_room	**path;
  unsigned int	i;

  if ((path = pmalloc(sizeof(t_room *) * (turn))) == NULL)
    return ;
  i = 0;
  while (i < turn - 1)
    {
      path[i] = ant->path[i];
      i = i + 1;
    }
  path[turn - 1] = room;
  free(ant->path);
  ant->path = path;
}

void	special_free(t_room **fr)
{
  if (fr)
    free(fr);
}
