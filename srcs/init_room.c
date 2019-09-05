/*
** init_room.c for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin/parser/srcs
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Apr 13 14:47:36 2015 lionel karmes
** Last update Fri May  1 15:51:36 2015 Steven Loo Fat
*/

#include "my.h"

int		init_list(t_list **list_room, t_list **list_tube,
			  t_start_end *start_end)
{
  if ((*list_room = new_list()) == NULL)
    return (-1);
  (*list_room)->what_element = ROOM;
  if ((*list_tube = new_list()) == NULL)
    return (-1);
  (*list_tube)->what_element = TUBE;
  start_end->start = NULL;
  start_end->end = NULL;
  return (0);
}

int		command_next(t_list **list_room, t_start_end *start_end,
			     char position)
{
  char		*buff;
  int		valid;

  while ((buff = get_next_line(0)))
    {
      my_putstr(buff);
      my_putchar('\n');
      buff = epur_str(buff);
      if (buff[0] != '\0')
	{
	  if (!(valid = room_is(buff, list_room, start_end, position)))
	    room_error(buff);
	  free(buff);
	  if (valid == 1)
	    return (position);
	  return (-1);
	}
      free(buff);
    }
  return (-1);
}
  
  int		init_room_next(t_list **list_room, t_list **list_tube,
			       char *str, t_start_end *start_end)
{
  int		valid;

  valid = command_is(str);
  if (valid == -1)
    return (-1);
  if (valid == START || valid == END)
    return (command_next(list_room, start_end, valid));
  valid = room_is(str, list_room, start_end, 0);
  if (valid != 0)
    return (valid);
  valid = tube_is(str, list_tube);
  if (valid != 0)
    return (valid);
  
  return (unknown_configuration(str)); /* Ni de commande, ni de salle, ni de tube */
}

int		init_room_end(t_list **list_room, t_start_end *start_end)
{
  if (start_end->start == NULL || start_end->end == NULL)
    return (start_end_error(0));
  my_put_in_list_start(list_room, start_end->start);
  my_put_in_list_end(list_room, start_end->end);
  return (0);
}

/*
-dans la fonction init_roon => a quoi sert la fonction check_room
 */

 int		valid_or_not(char *buff, t_list *list_room, t_list *list_tube, t_start_end *start_end)
{
  static int	line = 1;
  int		valid;

  line++;
  if (buff[0] != '\0')
    {
      if ((valid = init_room_next(&list_room, &list_tube, buff, start_end)) == -1)
	{
	  free(buff);
	  return (msg_error_line(line));
	}
      if (valid == START || valid == END)
	++line;
    }
  return (0);
}

int		init_room(t_list **list_room)
{
  char		*buff;
  t_start_end	start_end;
  t_list	*list_tube;

  if (init_list(list_room, &list_tube, &start_end))
    return (-1);
  while ((buff = get_next_line(0)))
    {
      my_putstr(buff);
      my_putchar('\n');
      epur_str(buff);      
      if (valid_or_not(buff, (*list_room), list_tube, &start_end) == -1)
	return (-1);
      free(buff);
    }
  if (init_room_end(list_room, &start_end))
    return (-1);
  return (check_room(list_room, list_tube));
}

/* 
-retirer la variable qui contient le nombre de ligne 
 */
