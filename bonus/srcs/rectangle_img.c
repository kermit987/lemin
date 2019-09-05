/*
** rectangle_img.c for  in /home/karmes_l/Projets/Igraph/Wolf3D/v3
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Tue Dec 23 12:03:00 2014 lionel karmes
** Last update Fri Jan  2 11:33:30 2015 lionel karmes
*/

#include "my.h"

void	rectangle_img(t_data_img *ptr_data_img, t_droite *droite, int color)
{
  int	y;
  int	x;

  if (droite->point1.x > droite->point2.x)
    my_swap(&(droite->point1.x), &(droite->point2.x));
  if (droite->point1.y > droite->point2.y)
    my_swap(&(droite->point1.y), &(droite->point2.y));
  y = droite->point1.y;
  while (y < droite->point2.y)
    {
      x = droite->point1.x;
      while (x < droite->point2.x)
	{
	  mlx_pixel_put_image(ptr_data_img, x, y, color);
	  x++;
	}
      y++;
    }
}
