/*
** add_type.c for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin/graph
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Apr 23 10:30:34 2015 lionel karmes
** Last update Fri May  1 15:29:29 2015 lionel karmes
*/

#include "my.h"

int		what_command(char *str)
{
  static int	how_start = 0;
  static int	how_end = 0;
  int		position;

  position = 0;
  if (my_strlen(str) > 2 && !my_strcmp("start", &str[2]))
    {
      position = START;
      ++how_start;
    }
  else  if (my_strlen(str) > 2 && !my_strcmp("end", &str[2]))
    {
      position = END;
      ++how_end;
    }
    if (how_start > 1 || how_end > 1)
      return (start_end_error(1, str));
    return (position);
}

int	handler_command(char **str)
{
  char	*buf;

  while ((buf = get_next_line(0)) && epur_str(buf)) /* il faudrait utilisé un epur_str mais il bug */
    {
      free(*str);
      *str = buf;
      if ((*str)[0] != '\0' && !is_room(*str))
	return (room_error(*str));
      else if ((*str)[0] != '\0')
	return (0);
    }
  return (-1);
}

int	add_room(t_list **list_room, t_start_end *start_end, char **str)
{
  int	position;
  char	**args;

  if ((position = what_command(*str)) == -1)
    return (-1);
  if (position == START || position == END)
    if (handler_command(str) == -1)
      return (-1);
  if ((args = my_str_to_wordtab(*str, ' ')) == NULL)
    return (-1);
  if ((find_element_room(*list_room, args[0]) ||
       (start_end->start != NULL &&
	!my_strcmp(start_end->start->name, args[0]))))
    return (error_multiple_room(args[0]));
  if (creat_room(args, list_room, start_end, position) == -1)
    {
      free_tab(args);
      return (-1);
    }
  free_tab(args);
  return (0);
}

int		add_move(t_list *list_room, t_list **list_move, char **args)
{
  int		i;
  t_move	*move;
  t_room	*room;
  char		**args2;
  static int	id = 0;

  i = 0;
  while (i < my_strtablen(args))
    {
      if (!(move = pmalloc(sizeof(t_move))))
	return (-1);
      move->id = ++id;
      args2 = my_str_to_wordtab(&args[i++][1], '-');
      move->ant = my_getnbr(args2[0]);
      if (!(room = find_element_room(list_room, args2[1])))
	{
	  room_error(args[2]);
	  free_tab(args2);
	  return (-1);
	}
      move->room = room;
      my_put_in_list_end(list_move, move);
      free_tab(args2);
    }
  return (0);
}

int		add_turn(t_coord *coord, char *str)
{
  char		**args;
  t_turn	*turn;
  t_list	*list_move;
  static int	id = 0;

  if (coord->list_turn->size == 0)
    id = 0;
  args = my_str_to_wordtab(str, ' ');
  if (!(turn = pmalloc(sizeof(t_turn))))
    return (-1);
  turn->id = ++id;
  if (!(list_move = new_list()))
    return (-1);
  list_move->what_element = MOVE;
  if (add_move(coord->list_room, &list_move, args) == -1)
    {
      free_tab(args);
      return (-1);
    }
  free_tab(args);
  turn->list_move = list_move;
  my_put_in_list_end(&(coord->list_turn), turn);
  return (0);
}
