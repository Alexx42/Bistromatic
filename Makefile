# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 13:19:44 by ale-goff          #+#    #+#              #
#    Updated: 2018/10/20 13:46:46 by ale-goff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = bistromatic.c\
			parsing.c\
			add.c\
			sub.c\
			eval_expr.c\
			help_operators.c\
			helpers.c\
			mult.c\
			div.c

OBJ = $(SRCS:.c=.o)

MAKE = make -C libft/

MAKEP = make -C ft_printf/

LIBRARY2 = ft_printf/libftprintf.a

LIBRARY = libft/libft.a

NAME = calc

INCLUDES = -I libft/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	gcc $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBRARY) $(LIBRARY2)
	gcc $(INCLUDES) $(OBJ) $(LIBRARY) $(LIBRARY2) -o $(NAME)

$(LIBRARY):
	$(MAKE)

$(LIBRARY2):
	$(MAKEP)

clean:
	/bin/rm -f $(OBJ) && $(MAKE) clean && $(MAKEP) clean

fclean: clean
	/bin/rm -f $(NAME) && $(MAKE) fclean && $(MAKEP) fclean

re: fclean all
