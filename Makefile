# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 01:28:54 by rcorenti          #+#    #+#              #
#    Updated: 2020/02/14 01:29:06 by rcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

DIR_S = srcs
HEADER = includes
DIR_O = obj
LIBFT = libft

SOURCES = ft_printf.c \
		  convert.c \
		  ft_check.c \
		  ft_print_s.c \
		  ft_print_digits.c \
		  ft_print_hexa.c \
		  ft_print_ptr.c \
		  ft_base.c \

OBJ = $(SOURCES:.c=.o)

SRCS = $(addprefix $(DIR_S)/, $(SOURCES))
OBJS = $(addprefix $(DIR_O)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
