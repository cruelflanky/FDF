# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 13:39:23 by vbrazhni          #+#    #+#              #
#    Updated: 2020/01/28 15:04:18 by gaudry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = $(LIBDIR)libft.a
LIBDIR = ./libft/
LIBHEAD = $(LIBDIR)

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADNAME = fdf.h\
	hotkeys.h
HEADDIR = ./inc/
HEADERS = $(addprefix $(HEADDIR), $(HEADNAME))

SRCDIR = ./src/
SRCNAME = main.c\
	atoi_base.c\
	checker.c\
	controls.c\
	hotkeys.c\
	init.c\
	print_map.c\
	projection.c\
	rgb.c
SOURCES = $(addprefix $(SRCDIR), $(SRCNAME))

OBJDIR = obj/
OBJNAME = $(patsubst %.c, %.o, $(SRCNAME))
OBJECTS	= $(addprefix $(OBJDIR), $(OBJNAME))

CC = gcc
FLAGS = -g -Wall -Werror -Wextra
LIBRARIES = -lmlx -lm -lft -L$(LIBDIR) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADDIR) -I$(LIBHEAD) -I$(MINILIBX_HEADERS)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJDIR) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)


$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o : $(SRCDIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -C $(LIBDIR) clean
	@$(MAKE) -C $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all