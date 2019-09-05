/*
** main.c for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin/parser
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Apr 13 14:11:48 2015 lionel karmes
** Last update Fri May  1 13:35:47 2015 Steven Loo Fat
*/

#include "my.h"
#include <stdio.h>

int		main()
{
  t_list	*list_room;
  char		*buffer;
  unsigned int	ants;

  if ((buffer = get_next_line(0)) == NULL)
      return (message_error_ants());
  if ((ants = (unsigned int)my_getnbr(buffer)) < 1)
    {
      my_putstrerror(INV_ANT_NBR);
      return (-1);
    }
  my_putnbr(ants);
  my_putchar('\n');
  if (init_room(&list_room) == -1)
    return (-1);
  lem_in(ants, list_room);
  return (0);
}
