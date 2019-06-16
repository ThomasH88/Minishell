# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2019/06/15 17:22:29 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

IDIR = include

HEADER = $(addprefix $(IDIR)/, minishell.h)

CC = gcc

LIB1 = libft/libft.a

LIB2 = libft/b_printf/libftprintf.a

FLAGS = -Wall -Werror -Wextra -I$(IDIR)

ODIR = obj

SDIR = src

OBJS = $(addprefix $(ODIR)/, minishell.o \
	   run_command.o \
	   side_funct.o \
	   string.o \
	   free.o	\
	   builtin_cmds.o \
	   included_cmds.o \
	   env_cmds.o \
	   cmds_helper.o \
	   get_env_var.o) 

$(ODIR)/%.o: $(SDIR)/%.c $(HEADER)
	@mkdir -p obj
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJS) $(LIB1) $(LIB2)
	$(CC) -o $@ $^ $(FLAGS)

$(LIB1):
	make -C libft/

all: $(NAME)

clean:
	make clean -C libft/
	/bin/rm -rf obj $(SRCO)

fclean: clean
	make fclean -C libft/
	/bin/rm -rf $(NAME) *.out* *.dSYM

re: fclean all

.PHONY: all clean fclean re
