/*
** fct_element.c for  in /home/karmes_l/Projets/Prog_Elem/Corewar/coreware_asm/asm/srcs
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Mar 31 16:33:23 2015 lionel karmes
** Last update Sat Apr 25 09:53:53 2015 lionel karmes
*/

#include "my.h"

t_room		*find_element_room(t_list *list, char *name)
{
  int		i;
  t_room	*tmp;

  i = 0;
  tmp = list->l_start;
  while (i < list->size)
    {
      if (name == NULL)
	my_putstr("NAME");
      else if (tmp->name == NULL)
	my_putstr("TMPNAME");
      if (!my_strcmp(name, tmp->name))
	return (tmp);
      tmp = tmp->e_next;
      i++;
    }
  return (NULL);
}

t_link_room	*find_element_link_room(t_list *list, char *name)
{
  int		i;
  t_link_room	*tmp;

  i = 0;
  tmp = list->l_start;
  while (i < list->size)
    {
      if (!my_strcmp(name, tmp->room->name))
	return (tmp);
      tmp = tmp->e_next;
      i++;
    }
  return (NULL);
}

void	print_list_link_room(t_link_room *tmp)
{
  while (tmp != NULL)
    {
      my_putstr("ID : ");
      my_putnbr(tmp->room->id);
      my_putstr("\nNAME : ");
      my_putstr(tmp->room->name);
      my_putstr("\nX : ");
      my_putnbr(tmp->room->x);
      my_putstr("\nY : ");
      my_putnbr(tmp->room->y);
      my_putstr("\nNBR LINK_ROOM : ");
      my_putnbr(tmp->room->link_room->size);
      my_putchar('\n');
      tmp = tmp->e_next;
    }
}

void	print_list_room(t_room *tmp)
{
  int	i;

  while (tmp != NULL)
    {
      my_putstr("ID : ");
      my_putnbr(tmp->id);
      my_putstr("\nNAME : ");
      my_putstr(tmp->name);
      my_putstr("\nX : ");
      my_putnbr(tmp->x);
      my_putstr("\nY : ");
      my_putnbr(tmp->y);
      my_putstr("\nNBR LINK_ROOM : ");
      my_putnbr(tmp->link_room->size);
      my_putstr("\nSIZE_ANTS : ");
      my_putnbr(tmp->size_ants);
      my_putstr("\nANTS : \n");
      i = 0;
      while (i < tmp->size_ants)
	{
	  my_putnbr(tmp->ants[i]);
	  my_putchar(' ');
	  i++;
	}
      my_putchar('\n');
      my_putstr("___________________ROOM\n");
      print_list_link_room(tmp->link_room->l_start);
      my_putstr("\n___________________ \n");
      tmp = tmp->e_next;
    }
}

void	print_list(t_list *list)
{
  if (list->what_element == ROOM)
    print_list_room((t_room *) list->l_start);
  else
    my_putstrerror("[ERROR] improbable : what_element ?\n");
}
