/*
** creat_room.c for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin/graph
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Apr 23 15:00:31 2015 lionel karmes
** Last update Fri Apr 24 10:15:00 2015 lionel karmes
*/

#include "my.h"

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
  room->size_ants = 0;
  room->ants = NULL;
  if (!(link_room = new_list()))
    return (-1);
  link_room->what_element = LINK_ROOM;
  room->link_room = link_room;
  if (position == START)
    start_end->start = room;
  else if (position == END)
    start_end->end = room;
  else
    my_put_in_list_end(list_room, room);
  return (0);
}
