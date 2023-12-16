# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davgalle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:25:23 by davgalle          #+#    #+#              #
#    Updated: 2023/12/16 20:21:11 by davgalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -O2 #-fsanitize=address -g3

RM = rm -f

LIB = ar rcs

SRCS = main.c \
	   ft_pushswap_unit.c \
	   ft_checker.c \
	   ft_errors.c \
	   ft_atoi_dav.c \
	   ft_splitdav.c \
	   ft_create_node.c \
	   ft_pushswap.c \
	   ft_rotate.c \
	   ft_rotatereverse.c \
	   ft_push.c \
	   ft_longsort.c \
	   ft_speed_node.c \
	   ft_mass_ordering.c

OBJTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJTS)

clean:
	$(RM) $(OBJTS)

fclean: clean
	$(RM) $(NAME)

re: all clean

.PHONY: all clean fclean re
