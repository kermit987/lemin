/*
** pixel_image.h for  in /home/karmes_l/Projets/FDF/test/lib/my
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Nov 17 15:19:15 2014 lionel karmes
** Last update Tue Apr 21 15:33:35 2015 lionel karmes
*/

#ifndef PIXEL_IMAGE_H_
# define PIXEL_IMAGE_H_

typedef struct	s_data_img
{
  void		*img_ptr;
  char		*data;
  int		bits_per_pixel;
  int		size_line;
}		t_data_img;

typedef struct	s_win_img
{
  void		*win_ptr;
  t_data_img	data_img;
  int		x;
  int		y;
}		t_win_img;

int		image(t_win_img *, void *);
void		mlx_pixel_put_image(t_data_img *, int, int, int);

#endif /* !PIXEL_IMAGE_H_ */
