# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davgalle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 15:34:52 by davgalle          #+#    #+#              #
#    Updated: 2023/11/21 15:14:40 by davgalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRCS = errors_free.c \
	   ft_split.c \
       main.c \
	   push_command.c \
	   push_swap.c \
	   push_swap_command.c \
	   push_swap_init.c \
	   reverse_rotate_command.c \
	   rotate_command.c \
	   stack_init.c \
	   stack_utils.c \
	   swap_command.c \
	   tiny_short.c

LIB = ar rcs

OBJTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJTS)

clean:
	$(RM) $(OBJTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

