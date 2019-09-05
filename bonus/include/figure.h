/*
** droite.h for  in /home/karmes_l/Projets/FDF/test/include
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Nov 17 12:07:10 2014 lionel karmes
** Last update Mon Apr 27 09:13:34 2015 lionel karmes
*/

#ifndef FIGURE_H_
# define FIGURE_H_

# include "pixel_image.h"

# define PI		(3.14159265359)
# define MAX(v1, v2)	((v1) > (v2) ? (v1) : (v2))
# define MIN(v1, v2)	((v1) < (v2) ? (v1) : (v2))

typedef struct	s_pixel
{
  int		x;
  int		y;
  int		color;
}		t_pixel;

typedef	struct	s_droite
{
  t_pixel	point1;
  t_pixel	point2;
}		t_droite;

void		droite_img(t_data_img *, t_droite *, int);
void		rectangle_img(t_data_img *, t_droite *, int);

#endif /* !FIGURE_H_ */
