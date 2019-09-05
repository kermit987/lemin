/*
** command.c for  in /home/loofat_s/rendu/CPE_2014_lemin/parser/srcs
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Mon Apr 13 15:48:40 2015 Steven Loo Fat
** Last update Sat May  2 18:34:39 2015 Aurélien Metz
*/

#include "my.h"

int		command_is(char *str)
{
  static int	how_many_start = 0;
  static int	how_many_end = 0;

  if (str[0] == '#' && str[1] == '#')
    {
      if (my_strcmp("start", &str[2]) == 0)
	{
	  how_many_start++;
	  if (how_many_start != 1)
	    return (start_end_error(1));
	  return (START);
	}
      else if (my_strcmp("end", &str[2]) == 0)
	{
	  how_many_end++;
	  if (how_many_end != 1)
	    return (start_end_error(1));
	  return (END);
	}
      return (-1);
    }
  return (0);
}

int		creat_room(char **args, t_list **list_room,
			   t_start_end *start_end, char position)
{
  static int	id = 0;
  t_room	*room;
  t_list	*link_room;

  if (!(room = pmalloc(sizeof(t_room))))
    return (-1);
  room->id = ++id;
  if (!(room->name = my_strdup(args[0])))
    return (-1);
  room->x = my_getnbr(args[1]);
  room->y = my_getnbr(args[2]);
  if (!(link_room = new_list()))
    return (-1);
  room->link_room = link_room;
  room->link_room->what_element = LINK_ROOM;
  if (position == START)
    start_end->start = room;
  else if (position == END)
    start_end->end = room;
  else
    my_put_in_list_end(list_room, room);
  return (0);
}

int		room_is(char *str, t_list **list_room,
			t_start_end *start_end, char position)
{
  char		**args;
  int		i;

  args = my_str_to_wordtab(str, ' ');
  if (my_strtablen(args) != 3)	/* Erreur si il n'y a pas d'argument pile poil */
    return (0);
  if ((find_element_room(*list_room, args[0])) ||
      (start_end->start != NULL &&
       !my_strcmp(start_end->start->name, args[0])))
    return (error_multiple_room(args[0]));
  i = 1;
  while (i < 3)
    if (!my_str_isnum(args[i++])) /* verifie qu'il y a que des nb numero chambre/coordonne/coordonne */
      {
	free_tab(args);
	return (room_error(str));
      }
  if (creat_room(args, list_room, start_end, position) == -1)
    {
      free_tab(args);
      return (-1);
    }
  free_tab(args);
  return (1);
}
