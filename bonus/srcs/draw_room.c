/*
** draw_room.c for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin/graph
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Apr 27 09:00:13 2015 lionel karmes
** Last update Mon Apr 27 17:26:56 2015 huy le
*/

#include "my.h"

void		draw_tube(t_list *list_room, t_win_img *img)
{
  t_link_room	*link_room;
  t_droite	tube;
  t_room	*room;

  room = list_room->l_start;
  while (room != NULL)
    {
      link_room = room->link_room->l_start;
      while (link_room != NULL)
	{
	  tube.point1.x = room->x;
	  tube.point1.y = room->y;
	  tube.point2.x = link_room->room->x;
	  tube.point2.y = link_room->room->y;
	  droite_img(&(img->data_img), &tube, 0);
	  link_room = link_room->e_next;
	}
      room = room->e_next;
    }
}

void	draw_room(t_coord *coord, t_win_img *img)
{
  t_droite	droite;
  t_room        *room;
  int		color;

  room = coord->list_room->l_start;
  draw_tube(coord->list_room, img);
  while (room != NULL)
    {
      if (room == coord->list_room->l_start)
	color = 0;
      else if (room == coord->list_room->l_end)
	color = 0xFFFFFF;
      else
	color = 16711680;
      droite.point1.x = room->x - 30;
      droite.point1.y = room->y + 30;
      droite.point2.x = room->x + 30;
      droite.point2.y = room->y - 30;
      rectangle_img(&(img->data_img), &droite, color);
      room = room->e_next;
    }
}
