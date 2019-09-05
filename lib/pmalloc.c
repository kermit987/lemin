/*
** pmalloc.c for  in /home/karmes_l/Projets/Systeme_Unix/minishell1/v2/lib
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Fri Jan 16 12:11:29 2015 lionel karmes
** Last update Thu Apr 30 15:52:09 2015 lionel karmes
*/

#include "my.h"

void	*pmalloc(int size)
{
  void	*bytes;

  if ((bytes = malloc(size)) == NULL)
    my_putstrerror("[ERROR] : malloc couldn't alloc\n");
  return (bytes);
}
