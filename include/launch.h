/*
** launch.h for lem in in /home/metz_a/rendu/CPE_2014_lemin
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Sun Apr 26 20:29:40 2015 Aurélien Metz
** Last update Sat May  2 18:31:49 2015 Steven Loo Fat
*/

#ifndef LAUNCH_H_
# define LAUNCH_H_

# include <stdlib.h>
# include <string.h>
# include "lem_in.h"
# include "list.h"

# define INF	(2147483646)

typedef struct	s_ant
{
  unsigned int	id;
  unsigned int	path_length;
  t_room	**path;
}		t_ant;

typedef	struct	s_branch
{
  unsigned int	weight;
  void		*tree;
}		t_branch;

typedef struct	s_tree
{
  t_room	*room;
  unsigned int	nbr_branches;
  t_branch	*branches;
}		t_tree;

/*
** prototypes
*/
t_tree		*build(t_ant *ants, t_room *room, t_room **fr, unsigned int turn);
int		shortest_path(t_tree *tree, t_ant *ant, unsigned int i);
int		allowed(t_room *room, t_room **fr);
t_branch	*lightest(t_tree *tree);
t_branch	*init_branches(t_room *room, t_room **fr);
int		booked(t_ant *ant, t_room *room, unsigned int turn);
int		tablen(t_room **tab);
void		*pmalloc(size_t size);
void		my_putstr(char *str);
void		special_free(t_room **fr);
void		aff(t_ant *ants, unsigned int nb_ants);
void		my_putchar(char c);
void		my_putnbr(int nb);
t_room		**refresh(t_room *room, t_room **fr);
void		init_paths(t_room *romm);
t_branch	*lightest(t_tree *tree);
void		add(t_ant *ant, t_room *room, unsigned int turn);
	
#endif /* !LEM_IN_H_ */
