/*
** tube_is.c for  in /home/loofat_s/rendu/CPE_2014_lemin/srcs
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Fri Apr 17 12:27:44 2015 Steven Loo Fat
** Last update Sat May  2 01:44:32 2015 Steven Loo Fat
*/

#include "my.h"
#include "lem_in.h"

int		tube_is(char *str, t_list **list_tube)
{
  t_tube	*tube;
  char		**tmp;

  if ((tube = malloc(sizeof(*tube))) == NULL)
    {
      my_putstr("Error: malloc in fidding_tube function failed\n");
      return (-1);
    }  
  tmp = my_str_to_wordtab(str, '-');
  if (my_strtablen(tmp) != 2)
    return (tube_error(str));
  if (!(tube->room1 = my_strdup(tmp[0])) || !(tube->room2 = my_strdup(tmp[1])))
    return (-1);
  if (!(my_strcmp(tube->room1, tube->room2)))
    {
      my_putstr("Error can't link room\n"); /* <--- j'ai pas trouver mieux xD */
      return (-1);
    }
  my_put_in_list_end(list_tube, tube);
  return (1);
}
