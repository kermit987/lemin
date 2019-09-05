/*
** my_wolf3D.c for  in /home/karmes_l/TP/Wolf3D
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Dec 15 10:53:11 2014 lionel karmes
** Last update Sat Apr 25 09:44:04 2015 huy le
*/

#include "my.h"

int		init_all(void *mlx_ptr, t_win_img *img, t_coord *coord)
{
  void		*win_ptr;

  if (parsing(coord) == -1)
    return (-1);
  if ((win_ptr = mlx_new_window(mlx_ptr, SIZE_WIN_X, SIZE_WIN_Y, "Lem-in"))
      == NULL)
    {
      my_putstrerror("[ERROR] : mlx_new_window()\n");
      return (-1);
    }
  img->win_ptr = win_ptr;
  img->x = SIZE_WIN_X;
  img->y = SIZE_WIN_Y;
  if (image(img, mlx_ptr) == -1)
    return (-1);
  return (0);
}

int		graph()
{
  void		*mlx_ptr;
  t_win_img	img;
  t_coord	coord;

  if ((mlx_ptr = mlx_init()) == NULL)
    {
      my_putstrerror("[ERROR] : mlx_init()\n");
      return (-1);
    }
  if (init_all(mlx_ptr, &img, &coord) == -1)
    return (-1);
  my_events(mlx_ptr, &img, &coord);
  return (0);
}
