/*
** put_element_room.c for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Apr 20 11:58:28 2015 lionel karmes
** Last update Mon Apr 20 16:53:12 2015 huy le
*/

#include "my.h"

void		put_end_element_link_room(t_list **list, t_link_room *element)
{
  t_link_room	*link_room_l_end;

  link_room_l_end = (*list)->l_end;
  element->e_next = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_prev = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      link_room_l_end->e_next = element;
      element->e_prev = (*list)->l_end;
      (*list)->l_end = element;
    }
  (*list)->size++;
}

void			put_start_element_link_room(t_list **list,
						    t_link_room *element)
{
  t_link_room		*link_room_l_start;

  link_room_l_start = (*list)->l_start;
  element->e_prev = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_next = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      link_room_l_start->e_prev = element;
      element->e_next = (*list)->l_start;
      (*list)->l_start = element;
    }
  (*list)->size++;
}
void		put_end_element_room(t_list **list, t_room *element)
{
  t_room	*room_l_end;

  room_l_end = (*list)->l_end;
  element->e_next = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_prev = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      room_l_end->e_next = element;
      element->e_prev = (*list)->l_end;
      (*list)->l_end = element;
    }
  (*list)->size++;
}

void		put_start_element_room(t_list **list, t_room *element)
{
  t_room	*room_l_start;

  room_l_start = (*list)->l_start;
  element->e_prev = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_next = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      room_l_start->e_prev = element;
      element->e_next = (*list)->l_start;
      (*list)->l_start = element;
    }
  (*list)->size++;
}
