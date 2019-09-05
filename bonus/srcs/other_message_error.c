/*
** other_message_error.c for  in /home/loofat_s/rendu/CPE_2014_lemin/srcs
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Tue Apr 21 15:07:39 2015 Steven Loo Fat
** Last update Fri May  1 15:33:27 2015 lionel karmes
*/

#include "my.h"

int	msg_error_line(int line)
{
  my_putstr("(error, line ");
  my_putnbr(line);
  my_putstr(")\n");
  return (-1);
}

int	message_error_ants()
{
  my_putstr("Error: missing ants\n");
  return (-1);
}

int	warning_multiple_pipe(char *room1, char *room2)
{
  my_putstrerror("[WARNING] : multiple inclusion of pipe : ");
  my_putstrerror(room1);
  my_putcharerror('-');
  my_putstrerror(room2);
  my_putcharerror('\n');
  return (0);
}

int	error_multiple_room(char *room)
{
  my_putstr("[ERROR] : multiple inclusion of room : ");
  my_putstr(room);
  my_putchar('\n');
  return (-1);
}
