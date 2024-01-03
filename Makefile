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

NAME_BONUS = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -O2 #-fsanitize=address -g3

RM = rm -f

LIB = ar rcs

SRCS = src/main.c \
	   src/ft_pushswap_unit.c \
	   src/ft_checker.c \
	   src/ft_errors.c \
	   src/ft_atoi_dav.c \
	   src/ft_splitdav.c \
	   src/ft_create_node.c \
	   src/ft_pushswap.c \
	   src/ft_rotate.c \
	   src/ft_rotatereverse.c \
	   src/ft_push.c \
	   src/ft_longsort.c \
	   src/ft_speed_node.c \
	   src/ft_mass_ordering.c \

BONUS_SRCS = bonus/main.c \
	   bonus/ft_pushswap_unit.c \
	   bonus/ft_checker.c \
	   bonus/ft_errors.c \
	   bonus/ft_atoi_dav.c \
	   bonus/ft_splitdav.c \
	   bonus/ft_create_node.c \
	   bonus/ft_pushswap.c \
	   bonus/ft_rotate.c \
	   bonus/ft_rotatereverse.c \
	   bonus/ft_push.c \
	   bonus/ft_longsort.c \
	   bonus/ft_speed_node.c \
	   bonus/ft_mass_ordering.c \
	   bonus/checker_bonus.c \

OBJTS = $(SRCS:.c=.o)

BONUS_OBJTS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJTS)

clean:
	$(RM) $(OBJTS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) $(OBJTS)
	$(RM) $(BONUS_OBJTS)

re: all clean

bonus: $(BONUS_OBJTS)
	ar rcs $(NAME_BONUS) $(BONUS_OBJTS)

.PHONY: all clean fclean re
