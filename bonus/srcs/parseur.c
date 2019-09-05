/*
** parseur.c for parseur in /home/le_n/rendu/progElem/CPE_2014_lemin/graph
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Wed Apr 22 16:16:30 2015 huy le
** Last update Fri May  1 12:18:17 2015 lionel karmes
*/

#include "my.h"

int	init_list(t_coord *coord, t_start_end *start_end)
{
  char	*buf;

  if ((buf = get_next_line(0)) == NULL)
    return (message_error_ants());
  coord->ants = my_getnbr(buf);
  free(buf);
  if (coord->ants < 1)
    {
      my_putstrerror(INV_ANT_NBR);
      return (-1);
    }
  if ((coord->list_room = new_list()) == NULL)
    return (-1);
  coord->list_room->what_element = ROOM;
  if ((coord->list_turn = new_list()) == NULL)
    return (-1);
  coord->list_turn->what_element = TURN;
  start_end->start = NULL;
  start_end->end = NULL;
  return (0);
}

int		raz_ant_room(t_list *list_room, int ants)
{
  int		i;
  t_room	*tmp;

  i = 0;
  tmp = list_room->l_start;
  if (tmp != NULL)
    {
      tmp->size_ants = ants;
      free(tmp->ants);
      if (!(tmp->ants = pmalloc(sizeof(int) * ants)))
	return (-1);
      while (i < ants)
	{
	  tmp->ants[i] = i + 1;
	  ++i;
	}
    }
  tmp = tmp->e_next;
  while (tmp != NULL)
    {
      tmp->size_ants = 0;
      if (tmp->ants)
	{
	  free(tmp->ants);
	  tmp->ants = NULL;
	}
      tmp = tmp->e_next;
    }
  return (0);
}

int	init_room_end(t_list **list_room, int ants, t_start_end *start_end)
{
  int	*tab_ants;
  int	i;

  if (start_end->start == NULL || start_end->end == NULL)
    return (start_end_error(0, NULL));
  start_end->start->size_ants = ants;
  if (!(tab_ants = pmalloc(sizeof(int) * ants)))
    return (-1);
  i = 0;
  while (i < ants)
    {
      tab_ants[i] = i + 1;
      ++i;
    }
  start_end->start->ants = tab_ants;
  my_put_in_list_start(list_room, start_end->start);
  my_put_in_list_end(list_room, start_end->end);
  return (0);
}

int		is_valid_buf(char **buf, t_start_end *start_end, t_coord *coord)
{
  static int	step = 0;
  int		type;

  if ((type = get_type(*buf)) == -1)
    return (unknown_configuration(*buf));
  if (step > type)
    return (-1);
  if (!type)
    if (add_room(&(coord->list_room), start_end, buf) == -1)
      return (-1);
  if (type == 1)
    {
      if (step == 0)
	if (init_room_end(&(coord->list_room), coord->ants, start_end) == -1)
	  return (-1);
      if (add_tube(&(coord->list_room), *buf) == -1)
	return (-1);
    }
  if (type == 2)
    if (add_turn(coord, *buf) == -1)
      return (-1);
  step = type;
  return (0);
}

int		parsing(t_coord *coord)
{
  char		*buf;
  t_start_end	start_end;

  if (init_list(coord, &start_end) == -1)
    return (-1);
  while ((buf = get_next_line(0)))
    {
      epur_str(buf);
      if (buf[0] != '\0' && is_valid_buf(&buf, &start_end, coord) == -1)
	{
	  free(buf);
	  return (-1);
	}
      free(buf);
    }
  return (0);
}
