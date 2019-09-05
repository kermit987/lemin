/*
** init_list.c for  in /home/karmes_l/Projets/Prog_Elem/PushSwap/v1
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Dec  9 14:41:33 2014 lionel karmes
** Last update Thu Apr 23 14:41:00 2015 lionel karmes
*/

#include "my.h"

void	my_put_in_list_end(t_list **list, void *element)
{
  if ((*list)->what_element == ROOM)
    put_end_element_room(list, (t_room *)element);
  else if ((*list)->what_element == LINK_ROOM)
    put_end_element_link_room(list, (t_link_room *)element);
  else if ((*list)->what_element == MOVE)
    put_end_element_move(list, (t_move *)element);
  else if ((*list)->what_element == TURN)
    put_end_element_turn(list, (t_turn *)element);
  else
    my_putstrerror("[ERROR] improbable : what_element ?1\n");
}

void	my_put_in_list_start(t_list **list, void *element)
{
  if ((*list)->what_element == ROOM)
    put_start_element_room(list, (t_room *)element);
  else if ((*list)->what_element == LINK_ROOM)
    put_start_element_link_room(list, (t_link_room *)element);
  else if ((*list)->what_element == MOVE)
    put_start_element_move(list, (t_move *)element);
  else if ((*list)->what_element == TURN)
    put_start_element_turn(list, (t_turn *)element);
  else
    my_putstrerror("[ERROR] improbable : what_element ?2\n");
}

t_list		*new_list()
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->size = 0;
  list->l_start = NULL;
  list->l_end = NULL;
  return (list);
}

void	remove_list(t_list **list)
{
  if (*list != NULL)
    {
      if ((*list)->what_element == ROOM)
	remove_list_room((t_room *)(*list)->l_start);
      else if ((*list)->what_element == LINK_ROOM)
	remove_list_link_room((t_link_room *)(*list)->l_start);
      else if ((*list)->what_element == MOVE)
	remove_list_move((t_move *)(*list)->l_start);
      else if ((*list)->what_element == TURN)
	remove_list_turn((t_turn *)(*list)->l_start);
      else
	my_putstrerror("[ERROR improbable ; what_element ?3\n");
      free(*list);
      *list = NULL;
    }
}
