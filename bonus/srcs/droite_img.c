/*
** droite.c for  in /home/karmes_l/Projets/FDF/test/droites
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Nov 17 12:01:32 2014 lionel karmes
** Last update Sat Apr 25 15:24:06 2015 huy le
*/

#include "my.h"

int	droite1_img(t_data_img *ptr_data_img, t_droite *coord, int color)
{
  int	y;
  int	x;

  if (coord->point1.x == coord->point2.x &&
      coord->point1.y == coord->point2.y)
    {
      mlx_pixel_put_image(ptr_data_img, coord->point1.x,
			  coord->point1.y, color);
      return (1);
    }
  if (coord->point2.x - coord->point1.x == 0)
    {
      y = coord->point2.y;
      while (y <= coord->point1.y)
	mlx_pixel_put_image(ptr_data_img, coord->point1.x, y++, color);
    }
  if (coord->point2.y - coord->point1.y == 0)
    {
      x = coord->point2.x;
      while (x <= coord->point1.x)
	mlx_pixel_put_image(ptr_data_img, x++, coord->point1.y, color);
    }
  return (0);
}

void	reverse_coord_droite_img(t_droite *coord)
{
  int	x;

      x = coord->point1.x;
      coord->point1.x = coord->point2.x;
      coord->point2.x = x;
      x = coord->point1.y;
      coord->point1.y = coord->point2.y;
      coord->point2.y = x;
}

int	droite2_img(t_data_img *ptr_data_img, t_droite *coord, int color)
{
  int	x;

  if (abs(coord->point2.x - coord->point1.x) >=
      abs(coord->point2.y - coord->point1.y))
    {
      if ((coord->point1.x > coord->point2.x &&
	   coord->point1.y < coord->point2.y) ||
	  (coord->point1.x > coord->point2.x &&
	   coord->point1.y > coord->point2.y))
	reverse_coord_droite_img(coord);
      x = coord->point1.x;
      while (x <= coord->point2.x)
	{
	  mlx_pixel_put_image(ptr_data_img, x,
			      coord->point1.y
			      + (coord->point2.y - coord->point1.y)
			      * (x - coord->point1.x)
			      / (coord->point2.x - coord->point1.x), color);
	  x++;
	}
      return (1);
    }
  return (0);
}

int	droite3_img(t_data_img *ptr_data_img, t_droite *coord, int color)
{
  int	y;

  if (abs(coord->point2.x - coord->point1.x) <
      abs(coord->point2.y - coord->point1.y))
    {
      if ((coord->point1.x < coord->point2.x &&
	   coord->point1.y > coord->point2.y) ||
	  (coord->point1.x > coord->point2.x &&
	   coord->point1.y > coord->point2.y))
	reverse_coord_droite_img(coord);
      y = coord->point1.y;
      while (y <= coord->point2.y)
	{
	  mlx_pixel_put_image(ptr_data_img, coord->point1.x
			      + (coord->point2.x - coord->point1.x)
			      * (y - coord->point1.y)
			      / (coord->point2.y - coord->point1.y),
			      y, color);
	  y++;
	}
      return (1);
    }
  return (0);
}

void	droite_img(t_data_img *ptr_data_img, t_droite *coord, int color)
{
  int	(*ptr_droites[3])(t_data_img *ptr_data_img,
			  t_droite *coord, int color);
  int	i;

  i = 0;
  ptr_droites[0] = &droite1_img;
  ptr_droites[1] = &droite2_img;
  ptr_droites[2] = &droite3_img;
  while (i < 3 && !ptr_droites[i](ptr_data_img, coord, color))
    i++;
}
