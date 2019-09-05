/*
** events.h for  in /home/karmes_l/Projets/Igraph/Wolf3D/v2
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Sat Dec 20 11:47:45 2014 lionel karmes
** Last update Sat Apr 25 10:37:29 2015 lionel karmes
*/

#ifndef EVENTS_H_
# define EVENTS_H_

# define K_ECHAP (65307)
# define K_RIGHT (65363)
# define K_LEFT (65361)
# define K_UP (65362)
# define K_DOWN (65364)
# define K_UP2 (65365)
# define K_DOWN2 (65366)
# define K_Z (122)
# define K_Y (121)
# define K_X (120)
# define K_E (101)
# define K_U (117)
# define K_C (99)
# define K_R (114)

typedef struct	s_param
{
  void		*mlx_ptr;
  t_win_img	*img;
  t_coord	*coord;
  t_turn	*current_turn;
  int		expose;
}		t_param;

void		my_events(void *, t_win_img *, t_coord *);

#endif /* !EVENTS_H_ */

