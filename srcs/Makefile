##
## Makefile for  in /home/karmes_l/Projets/Maths
## 
## Made by lionel karmes
## Login   <karmes_l@epitech.net>
## 
## Started on  Mon Nov  3 16:51:51 2014 lionel karmes
## Last update Mon Apr 27 12:05:54 2015 Aurélien Metz
##

#####################################################
CC	= 	gcc $(IFLAGS) $(CFLAGS) -g3
RM	= 	rm -f
CFLAGS	= 	-Wextra -Wall -Werror
CFLAGS	+=	-ansi -pedantic
IFLAGS	= 	-I ../include
LDFLAGS	= 	-lmy -L ..
NAME	= 	../lem_in
OBJS	= 	$(SRCS:.c=.o)
#####################################################
SRCS	= 	lem_in.c \
		launch.c \
		utils.c \
		aff.c \
	  	fct_list.c \
	  	fct_element.c \
	  	put_element.c \
	  	put_element_room.c \
	  	remove_element.c \
	  	init_room.c \
	  	command.c \
	  	other_message_error.c \
	  	message_error.c \
	        tube_is.c \
		check_room.c
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
