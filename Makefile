# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davgalle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:25:23 by davgalle          #+#    #+#              #
#    Updated: 2023/11/28 16:37:29 by davgalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

RM = rm -f

LIB = ar rcs

SRCS = main.c \
	   ft_splitdav.c \
	   ft_checker.c \
	   ft_free_strings.c \
	   ft_atoi_dav.c \
	   ft_create_node.c

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
