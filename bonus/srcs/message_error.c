/*
** command_error.c for  in /home/loofat_s/rendu/CPE_2014_lemin/parser/srcs
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Mon Apr 13 15:45:24 2015 Steven Loo Fat
** Last update Fri May  1 11:53:06 2015 lionel karmes
*/

#include "my.h"

int	command_error()
{
  my_putstr("Error: Invalid command\n");
  return (-1);
}

int	tube_error(char *str)
{
  my_putstr("Error: Invalid tube ");
  my_putstr(str);
  my_putchar('\n');
  return (-1);
}

int	room_error(char *str)
{
  my_putstr("Error: Invalid room ");
  my_putstr(str);
  my_putchar('\n');
  return (-1);
}

int	unknown_configuration(char *str)
{
  my_putstr("Error: Invalid configuration ");
  my_putstr(str);
  my_putchar('\n');
  return (-1);
}

int	start_end_error(int mode, char *str)
{
  if (mode == 0)
    my_putstr("Error: command ##start and ##end is required\n");
  else
    {
      my_putstr("Error: too many command ");
      my_putstr(str);
      my_putchar('\n');
    }
  return (-1);
}
