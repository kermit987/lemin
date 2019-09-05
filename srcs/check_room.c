/*
** check_room.c for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin/srcs
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Fri Apr 17 11:43:10 2015 lionel karmes
** Last update Sat May  2 18:53:49 2015 Steven Loo Fat
*/

#include "my.h"

int		is_a_multiple_inclusion_room(t_room *room1, t_room *room2)
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

int		check_room(t_list **list_room, t_list *list_tube)
{
  t_tube	*tmp_tube;
  t_room	*room1;
  t_room	*room2;

  tmp_tube = list_tube->l_start;
  while (tmp_tube)
    {
      if (!(room1 = find_element_room(*list_room, tmp_tube->room1)) ||
	  !(room2 = find_element_room(*list_room, tmp_tube->room2)))
	return (room_error((tmp_tube->room1) ?
			   tmp_tube->room1 : tmp_tube->room2));
      /* return (room_error((room1) ? */
      /* 			 tmp_tube->room2 : tmp_tube->room1)); */                    /*<----- LIONEL, DAFUQ ?!!!!!*/
      if (is_a_multiple_inclusion_room(room1, room2) == -1)
      	return (-1);/* savoir si il n;y a pas deux fois la salle relier deux fois  */
      tmp_tube = tmp_tube->e_next;
    }
  return (0);
}
