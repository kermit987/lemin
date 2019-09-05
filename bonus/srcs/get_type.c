/*
** get_type.c for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin/graph
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Apr 23 10:02:05 2015 lionel karmes
** Last update Fri May  1 11:44:03 2015 lionel karmes
*/

#include "my.h"

int	is_command(char *str)
{
  if (!(my_strncmp("##", str, 2)))
    return (1);
  return (0);
}

int	is_room(char *str)
{
  char	**args;
  int	i;

  args = my_str_to_wordtab(str, ' ');
  if (my_strtablen(args) != 3 || args[0][0] == 'P')
    {
      free_tab(args);
      return (0);
    }
  i = 1;
  while (i < 3)
    {
      if (!my_str_isnum(args[i]))
	{
	  free_tab(args);
	  return (0);
	}
      ++i;
    }
  free_tab(args);
  return (1);
}

int	is_tube(char *str)
{
 char	**args;

  args = my_str_to_wordtab(str, '-');
  if (my_strtablen(args) != 2 || args[0][0] == 'P')
    {
      free_tab(args);
      return (0);
    }
  free_tab(args);
  return (1);
}

int	is_move(char *str)
{
  char	**args;
  int	i;
  char	**args2;

  args = my_str_to_wordtab(str, ' ');
  i = 0;
  while (i < my_strtablen(args))
    {
      if (args[i][0] != 'P')
	{
	  free_tab(args);
	  return (0);
	}
      args2 = my_str_to_wordtab(&args[i][1], '-');
      if (my_strtablen(args2) != 2 || !my_str_isnum(args2[0]))
	{
	  free_tab(args);
	  free_tab(args2);
	  return (0);
	}
      free_tab(args2);
      i++;
    }
  free_tab(args);
  return (1);
}

int	get_type(char *str)
{
  if (is_command(str) || is_room(str))
    return (0);
  if (is_tube(str))
    return (1);
  if (is_move(str))
    return (2);
  return (-1);
}
