/*
** remove_commentaire.c for  in /home/loofat_s/rendu/CPE_2014_corewar/asm/lib
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Tue Mar 24 16:10:37 2015 Steven Loo Fat
** Last update Sat Apr 25 15:23:13 2015 huy le
*/

#include "my.h"

char	*remove_comment(char *str, char delimiter)
{
  int	i;

  i = 1;
  if (str[0] == delimiter && str[1] != delimiter)
    str[0] = '\0';
  while (str[i] != '\0')
    {
      if (str[i] == delimiter && str[i -1] != delimiter && str[i + 1]
	  == delimiter)
	str[i] = '\0';
      i++;
    }
  return (str);
}
