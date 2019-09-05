/*
** int_to_str.c for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin/graph
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Apr 27 17:47:58 2015 lionel karmes
** Last update Mon Apr 27 18:18:35 2015 lionel karmes
*/

#include "my.h"

char	*int_to_str(long nb)
{
  int	c;
  int	f;
  char	*str;

  c = count_num(nb);
  f = 0;
  if (nb < 0)
    {
      nb = -nb;
      f = 1;
    }
  if (!(str = pmalloc(sizeof(char) * (c + f + 1))))
    return (NULL);
  str[c + f] = '\0';
  if (f == 1)
    str[0] = '-';
  while (c > 0)
    {
      str[c + f - 1] = '0' + nb % 10;
      nb /= 10;
      c--;
    }
  return (str);
}
