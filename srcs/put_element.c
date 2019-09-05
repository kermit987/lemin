/*
** put_element.c for  in /home/loofat_s/rendu/CPE_2014_lemin/srcs
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Mon Apr 20 10:27:48 2015 Steven Loo Fat
** Last update Fri May  1 02:24:07 2015 Steven Loo Fat
*/

#include "my.h"

void		put_end_element_tube(t_list **list, t_tube *element)
{
  t_tube	*tube_l_end;

  tube_l_end = (*list)->l_end;
  element->e_next = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_prev = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      tube_l_end->e_next = element;
      element->e_prev = (*list)->l_end;
      (*list)->l_end = element;
    }
  (*list)->size++;
}

void		put_start_element_tube(t_list **list, t_tube *element)
{
  t_tube      	*tube_l_start;

  tube_l_start = (*list)->l_start;
  element->e_prev = NULL;
  if ((*list)->l_start == NULL)
    {
      element->e_next = NULL;
      (*list)->l_end = element;
      (*list)->l_start = element;
    }
  else
    {
      tube_l_start->e_prev = element;
      element->e_next = (*list)->l_start;
      (*list)->l_start = element;
    }
  (*list)->size++;
}
