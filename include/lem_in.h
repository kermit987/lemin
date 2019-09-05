/*
** lem-in.h for  in /home/karmes_l/Projets/Prog_Elem/Lem_in/CPE_2014_lemin
** 
** Made by lionel karmes
** Login   <karmes_l@epitech.net>
** 
** Started on  Mon Apr 13 13:41:02 2015 lionel karmes
** Last update Fri May  1 14:22:40 2015 lionel karmes
*/

#ifndef LEM_IN_H_
# define LEM_IN_H_
# define START 1
# define END 2

# include "list.h"

typedef struct		s_room
{
  int			id;
  char			*name;
  int			x;
  int			y;
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

typedef struct		s_tube
{
  char			*room1;
  char			*room2;
  struct s_tube		*e_next;
  struct s_tube		*e_prev;
}			t_tube;

typedef struct		s_start_end
{
  t_room		*start;
  t_room		*end;
}			t_start_end;

void		put_end_element_room(t_list **, t_room *);
void		put_start_element_room(t_list **, t_room *);
void		put_end_element_link_room(t_list **, t_link_room *);
void		put_start_element_link_room(t_list **, t_link_room *);
void		remove_list_room(t_room *);
void		remove_list_link_room(t_link_room *);
t_room		*find_element_room(t_list *, char *);
t_link_room    	*find_element_link_room(t_list *, char *);
void		put_end_element_tube(t_list **, t_tube *);
void		put_start_element_tube(t_list **, t_tube *);
void		remove_list_tube(t_tube *);
int		init_room(t_list **);
int		command_is(char *);
int		tube_is(char *str, t_list **list_tube);
int		tube_is_next(char *str, t_list **list_tube, t_tube tube);
int		msg_error_line(int);
int		warning_multiple_pipe(char *, char *);
int		error_multiple_room(char *);
int		command_error();
int		tube_error(char *);
int		room_error(char *);
int		unknown_configuration(char *);
int		start_end_error(int);
void		print_list_tube(t_tube *);
void		print_list_room(t_room *);
int		room_is(char *str, t_list **list_room, t_start_end *start_end, char position);
int		check_room(t_list **list_room, t_list *list_tube);

# define ROOM		(1)
# define TUBE		(2)
# define LINK_ROOM	(3)
# define INV_ANT_NBR	("[Error]: invalid number of ant\n")

#endif /* !LEM_IN_H */
