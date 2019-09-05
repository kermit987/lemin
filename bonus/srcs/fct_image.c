/*
** image.c for  in /home/karmes_l/Projets/FDF/test
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Sat Nov  8 10:13:45 2014 lionel karmes
** Last update Tue Apr 21 15:26:30 2015 lionel karmes
*/

#include "my.h"

void		mlx_pixel_put_image(t_data_img *ptr_data_img, int x, int y,
				    int color)
{
  unsigned long	pixel;

  if (x < SIZE_WIN_X && x >= 0 && y < SIZE_WIN_Y && y >= 0)
    {
      pixel = x * (ptr_data_img->bits_per_pixel / 8)
	+ ptr_data_img->size_line * y;
      ptr_data_img->data[pixel] = color;
      ptr_data_img->data[pixel + 1] = color >> 8;
      ptr_data_img->data[pixel + 2] = color >> 16;
    }
}

int		image(t_win_img *img, void *mlx_ptr)
{
  void		*img_ptr;
  char		*data;
  int		bits_per_pixel;
  int		size_line;
  int		endian;
  t_data_img	ptr_data_img;

  if ((img_ptr = mlx_new_image(mlx_ptr, img->x, img->y)) == NULL)
    {
      my_putstrerror("[ERROR] : mlx_new_image()\n");
      return (-1);
    }
  if ((data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian)
       ) == NULL)
    {
      my_putstrerror("[ERROR] : mlx_get_data_addr()\n");
      return (-1);
    }
  ptr_data_img.img_ptr = img_ptr;
  ptr_data_img.data = data;
  ptr_data_img.bits_per_pixel = bits_per_pixel;
  ptr_data_img.size_line = size_line;
  img->data_img = ptr_data_img;
  return (0);
}
