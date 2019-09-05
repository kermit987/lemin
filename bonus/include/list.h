/*
** list.h for  in /home/loofat_s/rendu/CPE_2014_lemin/srcs
** 
** Made by Steven Loo Fat
** Login   <loofat_s@epitech.net>
** 
** Started on  Mon Mar 23 12:16:50 2015 lionel karmes
** Last update Tue Apr 21 17:20:46 2015 Steven Loo Fat
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  int		size;
  void		*l_start;
  void		*l_end;
  int		what_element;
}		t_list;

void		my_put_in_list_end(t_list **, void *);
void		my_put_in_list_start(t_list **, void *);
t_list		*new_list();
void		remove_list(t_list **);
void		print_list(t_list *);

#endif /* !LIST_H_ */
