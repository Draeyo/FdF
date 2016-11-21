# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/03 09:30:30 by vlistrat          #+#    #+#              #
#    Updated: 2016/11/05 10:19:10 by vlistrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS_PATH = ./srcs/

SRCS_NAME = main.c ft_map.c close_key.c utility.c ft_alloc.c ft_draw.c \
			ft_calc.c

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

LIBFT_PATH = ./libft/

LIBFT_NAME = -lft

MLX_PATH = ./minilibx_macos/

MLX_NAME = -lmlx -lm

MLX = $(MLX_PATH) $(MLX_NAME)

LIBFT = $(LIBFT_PATH) $(LIBFT_NAME)

LIB_FLAGS = -L$(MLX_PATH) $(MLX_NAME) -L$(LIBFT_PATH) $(LIBFT_NAME) -framework OpenGL -framework AppKit

INC = ./includes/

CC = gcc -g

CFLAGS = -I $(INC) -I ./minilibx_macos/

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): makelibft $(OBJ)
	@(gcc -o $(NAME) $(OBJ) $(LIB_FLAGS))
	@(echo "\x1b[1;35m$(NAME)\x1b[0m \x1b[32mcreated.\x1b[0m \x1b[1;32m✓\x1b[0m")

makelibft:
	@(make -C $(LIBFT_PATH))

%.o: %.c
	@($(CC) -o $@ -c $< $(CFLAGS))

clean: cleanlibft
	@(/bin/rm -f $(OBJ))
	@(echo "\x1b[1;35mFdF\x1b[0m object files \x1b[31mcleaned.\x1b[0m \x1b[1;32m✓\x1b[0m")

cleanlibft:
	@(make -C $(LIBFT_PATH) clean)

fclean: clean fcleanlibft
	@(/bin/rm -f $(NAME))
	@(echo "\x1b[1;35m$(NAME)\x1b[0m \x1b[31mcleaned\x1b[0m. \x1b[1;32m✓\x1b[0m")

fcleanlibft:
	@(make -C $(LIBFT_PATH) fclean)

re: fclean all
