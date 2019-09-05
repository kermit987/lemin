/*
** launch.c for lem in in /home/metz_a/rendu/CPE_2014_lemin
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Sun Apr 26 20:27:55 2015 Aurélien Metz
** Last update Sat May  2 18:12:58 2015 Aurélien Metz
*/

#include "launch.h"

void		lem_in(unsigned int nb_ants, t_list *list_room)
{
  t_ant		*ants;
  t_tree	*tree;
  unsigned int	i;

  if (!(ants = pmalloc(sizeof(t_ant) * (nb_ants))))
    return ;
  i = 0;
  memset(ants, 0, sizeof(t_ant) * (nb_ants));
  while (i < nb_ants)
    {
      ants[i].id = i + 1;
      if ((tree = build(ants, list_room->l_start, NULL, 0)))
	if ((ants[i].path_length = shortest_path(tree, &ants[i], 0)))
	  return ;
      i = i + 1;
    }
  aff(ants, nb_ants);
}

int		shortest_path(t_tree *tree, t_ant *ant, unsigned int turn)
{
  t_branch	*tmp_weight;

  if (tree->room->e_next == NULL)
    return (0);
  if (turn != 0)
    add(ant, tree->room, turn);
  tmp_weight = lightest(tree);
  return (tmp_weight->weight
	  + shortest_path(tmp_weight->tree, ant, turn + tmp_weight->weight));
}

t_tree		*build(t_ant *ants, t_room *room,
		       t_room **fr, unsigned int turn)
{
  t_tree	*tree;
  unsigned int	i;
  t_link_room	*link;

  if ((tree = pmalloc(sizeof(t_tree))) == NULL)
    return (NULL);
  tree->room = room;
  if ((tree->branches = init_branches(room, fr)) == NULL)
    return (NULL);
  i = 0;
  link = room->link_room->l_start;
  while (link)
    {
      if (allowed(link->room, fr))
	{
	  tree->branches[i].weight = 1 + booked(ants, link->room, turn + 1);
	  tree->branches[i].tree = build(ants, link->room, refresh(room, fr),
					 turn + tree->branches[i].weight);
	}
      i = i + 1;
      link = link->e_next;
    }
  tree->nbr_branches = i;
  free(fr);
  return (tree);
}

t_room		**refresh(t_room *room, t_room **src)
{
  unsigned int	i;
  unsigned int	n;
  t_link_room	*link;
  t_room	**fr;

  if ((fr = pmalloc(sizeof(t_room *)
		    * (tablen(src) + room->link_room->size + 2))) == NULL)
    return (NULL);
  i = 0;
  while (src && src[i])
    {
      fr[i] = src[i];
      i = i + 1;
    }
  n = 0;
  link = room->link_room->l_start;
  while (link)
    {
      fr[i++] = link->room;
      link = link->e_next;
      n = n + 1;
    }
  fr[i++] = room;
  fr[i] = NULL;
  return (fr);
}

t_branch	*init_branches(t_room *room, t_room **fr)
{
  unsigned int	i;
  t_link_room	*link;
  t_branch	*branches;

  i = 0;
  link = room->link_room->l_start;
  while (link)
    {
      i += allowed(link->room, fr);
      link = link->e_next;
    }
  if ((branches = pmalloc(sizeof(t_branch) * (i + 1))) == NULL)
    return (NULL);
  memset(branches, 0, sizeof(t_branch) * (i + 1));
  return (branches);
}
