/*
** add_tube.c for add_tube in /home/le_n/rendu/progElem/CPE_2014_lemin/graph
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Sat Apr 25 15:35:48 2015 huy le
** Last update Fri May  1 15:31:38 2015 lionel karmes
*/

#include "my.h"

static int		is_a_multiple_inclusion_room(t_room *room1,
						     t_room *room2)
{
  t_link_room	*link_room1;
  t_link_room	*link_room2;

  if ((find_element_link_room(room1->link_room, room2->name)) ||
      (find_element_link_room(room2->link_room, room1->name)))
    warning_multiple_pipe(room1->name, room2->name);
  else
    {
      if (!(link_room1 = pmalloc(sizeof(t_link_room))) ||
      	  !(link_room2 = pmalloc(sizeof(t_link_room))))
      	return (-1);
      link_room1->room = room1;
      link_room2->room = room2;
      my_put_in_list_end(&(room1->link_room), link_room2);
      my_put_in_list_end(&(room2->link_room), link_room1);
    }
  return (0);
}

int		add_tube(t_list **list_room, char *str)
{
  char		**args;
  t_room	*room1;
  t_room	*room2;

  if ((args = my_str_to_wordtab(str, '-')) == NULL)
    return (-1);
  if (!(room1 = find_element_room(*list_room, args[0])) ||
      !(room2 = find_element_room(*list_room, args[1])))
    {
      room_error((room1) ? args[0] : args[1]);
      free_tab(args);
      return (-1);
    }
  if (is_a_multiple_inclusion_room(room1, room2) == -1)
    {
      free_tab(args);
      return (-1);
    }
  free_tab(args);
  return (0);
}
