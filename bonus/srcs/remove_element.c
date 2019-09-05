/*
** remove_element.c for  in /home/karmes_l/Projets/Systeme_Unix/minishell2/v1/minishell2
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Feb 26 20:12:07 2015 lionel karmes
** Last update Mon Apr 27 11:43:17 2015 lionel karmes
*/

#include "my.h"

void			remove_list_link_room(t_link_room *tmp)
{
  t_link_room      	*element;

  while (tmp != NULL)
    {
      element = tmp;
      tmp = tmp->e_next;
      free(element);
    }
}

void		remove_list_room(t_room *tmp)
{
  t_room	*element;

  while (tmp != NULL)
    {
      element = tmp;
      if (tmp->name)
	free(tmp->name);
      if (tmp->ants)
	free(tmp->ants);
      remove_list(&(tmp->link_room));
      tmp = tmp->e_next;
      free(element);
    }
}

void		remove_list_move(t_move *tmp)
{
  t_move	*element;

  while (tmp != NULL)
    {
      element = tmp;
      tmp = tmp->e_next;
      free(element);
    }
}

void		remove_list_turn(t_turn *tmp)
{
  t_turn	*element;

  while (tmp != NULL)
    {
      element = tmp;
      remove_list(&(tmp->list_move));
      tmp = tmp->e_next;
      free(element);
    }
}
