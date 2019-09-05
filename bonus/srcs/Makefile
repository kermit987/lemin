##
## Makefile for  in /home/karmes_l/Projets/Maths
## 
## Made by lionel karmes
## Login   <karmes_l@epitech.net>
## 
## Started on  Mon Nov  3 16:51:51 2014 lionel karmes
## Last update Fri May  1 12:16:54 2015 lionel karmes
##

#####################################################
CC	= 	gcc $(IFLAGS) $(CFLAGS) -g3
RM	= 	rm -f
CFLAGS	= 	-Wextra -Wall -Werror
CFLAGS	+=	-ansi -pedantic
IFLAGS	= 	-I ../include
LDFLAGS	=	-L ../ -lmy -L minilibx -lmlx -L usr/lib64/X11 -lXext -lX11
NAME	= 	../visu-hex
OBJS	= 	$(SRCS:.c=.o)
#####################################################
SRCS	=	main.c \
		graph.c \
		fct_image.c \
		my_events.c \
		droite_img.c \
		rectangle_img.c \
		fct_list.c \
		fct_element.c \
		put_element_room.c \
		put_element.c \
		remove_element.c \
		parseur.c \
		get_type.c \
		add_type.c \
		add_tube.c \
		creat_room.c \
		message_error.c \
		other_message_error.c \
		draw.c \
		draw_room.c \
#####################################################
all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

.c.o:
		@printf "\033[36m[gcc]\033[37m  $<\n"
		@$(CC) $(LDFLAGS) -c $< -o $@
		@printf "\033[0m"

clean:
		@$(RM) $(OBJS)

fclean: 	clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
#####################################################
