/*
** graph.h for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin/graph/include
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Thu Apr 23 13:08:24 2015 lionel karmes
** Last update Fri May  1 15:29:11 2015 lionel karmes
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# include "list.h"

# define SIZE_WIN_X 1000
# define SIZE_WIN_Y 1000

typedef struct		s_room
{
  int			id;
  char			*name;
  int			x;
  int			y;
  int			size_ants;
  int			*ants;
  t_list		*link_room;
  struct s_room		*e_next;
  struct s_room		*e_prev;
}			t_room;

typedef struct		s_link_room
{
  t_room		*room;
  struct s_link_room	*e_next;
  struct s_link_room	*e_prev;
}			t_link_room;

typedef struct		s_start_end
{
  t_room		*start;
  t_room		*end;
}			t_start_end;

typedef struct	s_move
{
  int		id;
  int		ant;
  t_room	*room;
  struct s_move	*e_next;
  struct s_move	*e_prev;
}		t_move;

typedef struct	s_turn
{
  int		id;
  t_list	*list_move;
  struct s_turn	*e_next;
  struct s_turn	*e_prev;
}		t_turn;

typedef struct	s_coord
{
  t_list        *list_room;
  t_list	*list_turn;
  int		ants;
}		t_coord;

int		graph();
int		parsing(t_coord *);
int		raz_ant_room(t_list *, int);
int		draw(t_coord *, t_win_img *, t_turn *, void *);
void		draw_room(t_coord *, t_win_img *);
int		get_type(char *);
int		is_room(char *);
int		add_room(t_list **, t_start_end *, char **);
int		add_tube(t_list **, char *);
int		add_turn(t_coord *, char *);
int		creat_room(char **, t_list **, t_start_end *, char);
void		put_end_element_room(t_list **, t_room *);
void		put_start_element_room(t_list **, t_room *);
void		put_end_element_link_room(t_list **, t_link_room *);
void		put_start_element_link_room(t_list **, t_link_room *);
void		put_end_element_move(t_list **, t_move *);
void		put_start_element_move(t_list **, t_move *);
void		put_end_element_turn(t_list **, t_turn *);
void		put_start_element_turn(t_list **, t_turn *);
void		remove_list_room(t_room *);
void		remove_list_link_room(t_link_room *);
void		remove_list_move(t_move *);
void		remove_list_turn(t_turn *);
t_room		*find_element_room(t_list *, char *);
t_link_room    	*find_element_link_room(t_list *, char *);
int		msg_error_line(int);
int		warning_multiple_pipe(char *, char *);
int		error_multiple_room(char *);
int		command_error();
int		tube_error(char *);
int		room_error(char *);
int		unknown_configuration(char *);
int		start_end_error(int, char *);
void		print_list_room(t_room *);

# define START 1
# define END 2

# define ROOM		(1)
# define LINK_ROOM	(2)
# define MOVE		(3)
# define TURN		(4)

# define INV_ANT_NBR	("[Error]: invalid number of ant\n")

#endif /* !GRAPH_H_ */
