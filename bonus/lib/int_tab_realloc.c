/*
** int_tab_realloc.c for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin/graph/lib
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Apr 23 17:02:45 2015 lionel karmes
** Last update Mon Apr 27 09:55:24 2015 lionel karmes
*/

#include "my.h"

int	*int_tab_realloc(int *tab, int size_after, int size)
{
  int	*new_tab;
  int	i;

  if (size_after > 0)
    if (!(new_tab = pmalloc(sizeof(int) * size_after)))
      return (NULL);
  i = 0;
  while (i < size_after && i < size)
    {
      new_tab[i] = tab[i];
      ++i;
    }
  while (i < size_after)
    {
      new_tab[i] = 0;
      ++i;
    }
  if (tab)
    free(tab);
  return (new_tab);
}
