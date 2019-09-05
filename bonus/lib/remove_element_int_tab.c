/*
** remove_element_int_tab.c for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin/graph/lib
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Apr 23 22:19:38 2015 lionel karmes
<<<<<<< HEAD
** Last update Mon Apr 27 09:58:02 2015 lionel karmes
=======
** Last update Sat Apr 25 11:06:15 2015 huy le
>>>>>>> ab59997e66f859433be59ef3f1f2913fcfae32f3
*/

#include "my.h"
#include <stdio.h>

int		remove_element_int_tab(int element, int **tab, int size)
{
  int		i;

  i = 0;
  while (i < size && (*tab)[i] != element)
    ++i;
  if (i <  size)
    {
      while (i + 1 < size)
	{
	  (*tab)[i] = (*tab)[i + 1];
	  ++i;
	}
      if (size - 1 == 0)
	{
	  free(*tab);
	  *tab = NULL;
	}
      else if (!((*tab) = int_tab_realloc((*tab), size - 1, size)))
	return (-1);
      return (1);
    }
  return (0);
}
