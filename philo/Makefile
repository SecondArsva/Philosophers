# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 15:50:51 by davidga2          #+#    #+#              #
#    Updated: 2023/10/21 16:39:07 by davidga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc -Wall -Wextra -Werror
RM = rm -rf

SRC = main.c	\
OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRC) -o $(NAME)

%.o:%.c
	$(CC) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
