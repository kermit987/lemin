/*
** put_element.c for  in /home/loofat_s/rendu/CPE_2014_lemin/srcs
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
<<<<<<< HEAD
** Started on  Mon Apr 20 10:27:48 2015 Steven Loo Fat
** Last update Thu Apr 23 14:42:41 2015 lionel karmes
=======
** Started on  Thu Feb 26 19:55:46 2015 lionel karmes
** Last update Mon Apr 20 17:39:29 2015 huy le
>>>>>>> 6e5ae0b980e7dde108075941f713785e51cbc757
*/

#include "my.h"

void		put_end_element_move(t_list **list, t_move *element)
{
  t_move	*move_l_end;

  move_l_end = (*list)->l_end;
  element->e_next = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_prev = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      move_l_end->e_next = element;
      element->e_prev = (*list)->l_end;
      (*list)->l_end = element;
    }
  (*list)->size++;
}

void		put_start_element_move(t_list **list, t_move *element)
{
  t_move      	*move_l_start;

  move_l_start = (*list)->l_start;
  element->e_prev = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_next = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      move_l_start->e_prev = element;
      element->e_next = (*list)->l_start;
      (*list)->l_start = element;
    }
  (*list)->size++;
}

void		put_end_element_turn(t_list **list, t_turn *element)
{
  t_turn	*turn_l_end;

  turn_l_end = (*list)->l_end;
  element->e_next = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_prev = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      turn_l_end->e_next = element;
      element->e_prev = (*list)->l_end;
      (*list)->l_end = element;
    }
  (*list)->size++;
}

void		put_start_element_turn(t_list **list, t_turn *element)
{
  t_turn      	*turn_l_start;

  turn_l_start = (*list)->l_start;
  element->e_prev = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_next = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      turn_l_start->e_prev = element;
      element->e_next = (*list)->l_start;
      (*list)->l_start = element;
    }
  (*list)->size++;
}
