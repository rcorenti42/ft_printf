# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 02:55:15 by rcorenti          #+#    #+#              #
#    Updated: 2020/01/30 04:18:11 by rcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft*.c
HDRS = libft.h
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I $(HDRS) -c $(SRCS)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
