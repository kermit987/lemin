/*
** remove_element.c for  in /home/karmes_l/Projets/Systeme_Unix/minishell2/v1/minishell2
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Feb 26 20:12:07 2015 lionel karmes
** Last update Mon Apr 20 12:40:09 2015 lionel karmes
*/

#include "my.h"

void		remove_list_room(t_room *tmp)
{
  t_room      	*element;

  while (tmp != NULL)
    {
      element = tmp;
      if (tmp->name != NULL)
	free(tmp->name);
      tmp = tmp->e_next;
      free(element);
    }
}

void		remove_list_link_room(t_link_room *tmp)
{
  t_link_room      	*element;

  while (tmp != NULL)
    {
      element = tmp;
      tmp = tmp->e_next;
      free(element);
    }
}

void		remove_list_tube(t_tube *tmp)
{
  t_tube      	*element;

  while (tmp != NULL)
    {
      element = tmp;
      if (tmp->room1 != NULL)
	free(tmp->room1);
      if (tmp->room2 != NULL)
	free(tmp->room2);
      tmp = tmp->e_next;
      free(element);
    }
}
