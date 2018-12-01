# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2018/10/21 19:42:43 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = b_printf.h/

FLAGS = -Wall -Werror -Wextra -c

SRCS = b_printf.c \
	  ft_putnbr_printf.c \
	  ft_string.c \
	  itoa_base.c \
	  p_itoa_base.c

SRCO = $(SRCS:%.c=%.o)

$(NAME):
	gcc $(FLAGS) $(SRCS) -I=$(INCLUDES)
	ar rcs $(NAME) $(SRCO)
all: $(NAME)

run: re
	gcc main*.c -L. -lftprintf -I $(INCLUDES)
clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME) *.out

re: fclean all
