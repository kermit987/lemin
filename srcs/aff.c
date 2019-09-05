/*
** aff.c for lem in in /home/metz_a/rendu/CPE_2014_lemin
** 
** Made by Aurélien Metz
** Login   <metz_a@epitech.net>
** 
** Started on  Mon Apr 27 10:45:57 2015 Aurélien Metz
** Last update Tue Apr 28 11:01:42 2015 Aurélien Metz
*/

#include "launch.h"

unsigned int	max(t_ant *ants, unsigned int nb_ants)
{
  unsigned int i;
  unsigned int max;

  i = 0;
  max = ants[0].path_length;
  while (i < nb_ants)
    {
      if (max < ants[i].path_length)
	max = ants[i].path_length;
      i = i + 1;
    }
  return (max);
}

void		aff_move(t_ant *ant, unsigned int turn)
{
  my_putchar('P');
  my_putnbr(ant->id);
  my_putchar('-');
  my_putstr(ant->path[turn]->name);
  my_putchar(' ');
}

void		aff(t_ant *ants, unsigned int nb_ants)
{
  unsigned int	maximum;
  unsigned int	turn;
  unsigned int	i;

  turn = 0;
  if ((maximum = max(ants, nb_ants)) >= INF)
    return ;
  while (turn < maximum)
    {
      i = 0;
      while (i < nb_ants)
	{
	  if ((turn <= ants[i].path_length)
	      && (ants[i].path[turn]))
	    aff_move(ants + i, turn);
	  i = i + 1;
	}
      my_putchar('\n');
      turn = turn + 1;
    }
}
