/*
** my_events.c for  in /home/karmes_l/TP/tp1_minilibx_et_evenements/ex3
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Nov 10 15:18:33 2014 lionel karmes
<<<<<<< HEAD:graph/my_events.c
** Last update Mon Apr 27 12:58:50 2015 huy le
=======
** Last update Mon Apr 27 18:15:30 2015 lionel karmes
>>>>>>> 15edb9b82ef306f2c65a00629392247df25fd67c:bonus/srcs/my_events.c
*/

#include "my.h"


void	free_all(t_coord *coord)
{
  remove_list(&(coord->list_room));
  remove_list(&(coord->list_turn));
  exit(1);
}

void	print_turn(t_param *mlx)
{
  char		*turn;

  mlx_string_put(mlx->mlx_ptr, mlx->img->win_ptr, 0, 10, 0x000000,
		 "Tour numero : ");
  if (!(turn = int_to_str((mlx->current_turn == NULL) ?
			  0 : mlx->current_turn->id)))
    free_all(mlx->coord);
  mlx_string_put(mlx->mlx_ptr, mlx->img->win_ptr, 100, 10, 0x000000, turn);
  free(turn);
}

int		gere_expose(void *param)
{
  t_param	*mlx;

  mlx = param;
  if (mlx->expose == 2)
    {
      if (draw(mlx->coord, mlx->img, NULL, mlx->mlx_ptr) == -1)
	free_all(mlx->coord);
    }
  if (mlx->expose == 1 && mlx->current_turn != NULL)
    {
      if (draw(mlx->coord, mlx->img, mlx->current_turn, mlx->mlx_ptr) == -1)
	free_all(mlx->coord);
    }
  mlx->expose = 0;
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->img->win_ptr,
			  mlx->img->data_img.img_ptr, 0, 0);
  print_turn(mlx);
  return (0);
}

int		gere_key(int keycode, void *param)
{
  t_param	*mlx;

  mlx = param;
  if (keycode == K_ECHAP)
    free_all(mlx->coord);
  else if (keycode == K_RIGHT)
    {
      mlx->expose = 1;
      if (mlx->current_turn == NULL)
	mlx->current_turn = mlx->coord->list_turn->l_start;
      else if (mlx->current_turn->e_next != NULL)
	mlx->current_turn = mlx->current_turn->e_next;
      else
	mlx->expose = 0;
      gere_expose(param);
    }
  else if (keycode == K_R)
    {
      raz_ant_room(mlx->coord->list_room, mlx->coord->ants);
      mlx->expose = 2;
      mlx->current_turn = NULL;
      gere_expose(param);
    }
  return (0);
}

void		my_events(void *mlx_ptr, t_win_img *img, t_coord *coord)
{
  t_param	param;

  param.mlx_ptr = mlx_ptr;
  param.img = img;
  param.coord = coord;
  param.current_turn = NULL;
  param.expose = 2;
  mlx_key_hook(img->win_ptr, gere_key, &param);
  mlx_expose_hook(img->win_ptr, gere_expose, &param);
  mlx_loop(mlx_ptr);
}
