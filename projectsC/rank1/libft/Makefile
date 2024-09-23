# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joao-rde <joao-rde@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 15:12:37 by joao-rde          #+#    #+#              #
#    Updated: 2024/09/23 18:06:09 by joao-rde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS= -Wall -Wextra -Werror
SOURCES = $(shell ls *.c)
OBJECTS	= $(SOURCES:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
