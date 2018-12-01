# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2018/10/28 15:50:38 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

HEADER = minishell.h

LIB1 = libft/libft.a

LIB2 = libft/b_printf/libftprintf.a

FLAGS = -Wall -Werror -Wextra -o

SRCS = minishell.c \
	   run_command.c \
	   side_funct.c \
	   string.c \
	   free.c	\
	   builtin_cmds.c \
	   included_cmds.c \
	   env_cmds.c \
	   cmds_helper.c \
	   get_env_var.c \

SRCO = $(SRCS:.c=.o)

$(NAME):
	make -C libft/
	gcc $(FLAGS) $(NAME) $(SRCS) $(LIB1) $(LIB2) -I=$(HEADER)

all: $(NAME)

san: fclean
	make -C libft/
	gcc -fsanitize=address -g $(FLAGS) $(NAME) $(SRCS) $(LIB1) $(LIB2) -I=$(HEADER)

clean:
	make clean -C libft/
	/bin/rm -f $(SRCO)

fclean: clean
	make fclean -C libft/
	/bin/rm -rf $(NAME) *.out* *.dSYM

re: fclean all

git: fclean
	git add .
	git reset HEAD *main*
	git status
	git commit -m "update"
	git push
