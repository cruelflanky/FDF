# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/21 13:52:45 by gaudry            #+#    #+#              #
#    Updated: 2019/12/21 15:15:29 by gaudry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MAIN = main.c

#SRC = solver.c checker.c map.c figures.c

LIB = ./libft/

FLAGS = -lmlx -framework OpenGl -framework AppKit

all: $(NAME)
$(NAME):
	gcc -o $(NAME) $(MAIN) $(FLAGS)

clean:
	@$(MAKE) -C $(LIB) clean

fclean: clean
	@$(MAKE) -C $(LIB) fclean
	rm -f $(NAME)

re: fclean all