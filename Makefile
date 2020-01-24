# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/21 13:52:45 by gaudry            #+#    #+#              #
#    Updated: 2020/01/24 17:07:17 by gaudry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

SRCDIR = ./src/
SRCNAME = main.c\
	hotkeys.c\
	init.c\
	controls.c\
	checker.c\
	projection.c\
	print_map.c\
	atoi_base.c\
	rgb.c
SRC = $(addprefix $(SRCDIR), $(SRCNAME))

OBJNAME = $(SRS:.c=.o)
OBJDIR = ./obj/
OBJECTS	= $(addprefix $(OBJDIR), $(OBJNAME))

HEADNAME = fdf.h\
	hotkeys.h\
HEADIR = ./inc/
LIBDIR = ./libft/
LIB = $(LIBDIR)libft.a
HEADERS = $(addprefix $(HEADDIR), $(HEADNAME))

MINILIBXDIR = ./minilibx_macos/
MINILIBFLAGS = -lmlx -framework OpenGl -framework AppKit
MINILIBX = $(MINILIBXDIR)libmlx.a

INCLUDES = -I$(HEADDIR) -I$(LIBDIR) -I$(MINILIBXDIR)
LIBAS = -L $(LIBDIR) -L $(MINILIBXDIR)
FLAGS = -g -Wall -Wextra -Werror $(MINILIBFLAGS)

all: $(NAME)

$(NAME): $(OBJDIR) $(LIB) $(MINILIBX)
	$(CC) $(FLAGS) $(LIBAS) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJDIR):
	@if [ ! -d $(OBJDIR) ]; then \
		mkdir $(OBJDIR); \
	fi
	$(CC) $(FLAGS) -c $(INCLUDES) $(SRCDIR)%.c $(HEADERS) -o $(OBJDIR)%.o

$(LIB):
	@$(MAKE) -C $(LIBDIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBXDIR)
clean:
	@$(MAKE) -C $(LIB) clean
	@$(MAKE) -C $(MINILIBXDIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(LIB)
	@rm -f $(MINILIBX)
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all