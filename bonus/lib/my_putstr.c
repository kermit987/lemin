/*
** my_putstr.c for my_putstr in /home/karmes_l/test/tmp_Piscine_C_J04
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Oct  2 11:14:15 2014 lionel karmes
** Last update Fri Apr 17 12:02:27 2015 lionel karmes
*/

#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (*(str + i) != '\0')
    {
      my_putchar(*(str + i));
      i = i + 1;
    }
}
