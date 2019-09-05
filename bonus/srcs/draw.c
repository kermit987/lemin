/*
** draw.c for draw in /home/le_n/rendu/progElem/CPE_2014_lemin/graph
** 
** Made by huy le
** Login   <le_n@epitech.net>
** 
** Started on  Thu Apr 23 12:12:08 2015 huy le
<<<<<<< HEAD
** Last update Thu Apr 30 17:30:02 2015 lionel karmes
=======
** Last update Thu Apr 30 17:11:45 2015 Steven Loo Fat
>>>>>>> cd9e13a4c5e89cce31889da9073d88e94927235f
*/

#include "my.h"
#include <stdio.h>

static void	fill_screen(t_win_img *img)
{
  int		x;
  int		y;

  y = 0;
  while (y < img->y)
    {
      x = 0;
      while (x < img->x)
	{
	  mlx_pixel_put_image(&(img->data_img), x, y, 10092390);
	  x++;
	}
      y++;
    }
}

static void	draw_ants(t_coord *coord, t_win_img *img)
{
  t_droite	droite;
  t_room	*room;

  room = coord->list_room->l_start;
  while (room != NULL)
    {
      if (room->size_ants != 0)
	{
	  droite.point1.x = room->x - 10;
	  droite.point1.y = room->y + 10;
	  droite.point2.x = room->x + 10;
	  droite.point2.y = room->y - 10;
	  rectangle_img(&(img->data_img), &droite, 255);
	}
      room = room->e_next;
    }
}

static int	remove_ant(t_room *room, int ant)
{
  int		valid;

  while (room)
    {
      if ((valid = remove_element_int_tab(ant, &room->ants, room->size_ants))
	  == -1)
	{
	  return (-1);
	}
      if (valid)
	--(room->size_ants);
      room = room->e_next;
    }
  return (1);
}

static int	some_ants(t_coord *coord, t_win_img *img, t_turn *current_turn)
{
  t_move	*move;

  move = current_turn->list_move->l_start;
  while (move)
    {
      if (remove_ant(coord->list_room->l_start, move->ant) == -1)
	return (-1);
      if (!(move->room->ants = int_tab_realloc(move->room->ants,
					       move->room->size_ants + 1,
					       move->room->size_ants)))
	return (-1);
      move->room->ants[move->room->size_ants] = move->ant;
      move->room->size_ants++;
      move = move->e_next;
    }
  draw_ants(coord, img);
  return (0);
}

int	draw(t_coord *coord, t_win_img *img, t_turn *turn, void *mlx_ptr)
{
  (void)mlx_ptr;
  fill_screen(img);
  /* mlx_xpm_file_to_image(mlx_ptr, "lemin", &width, &height); */
  draw_room(coord, img);
  if (turn == NULL)
    {
      draw_ants(coord, img);
      return (0);
    }
  if (some_ants(coord, img, turn) == -1)
    return (-1);
  return (0);
}
