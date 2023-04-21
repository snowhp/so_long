# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 16:21:48 by tde-sous          #+#    #+#              #
#    Updated: 2023/04/21 12:42:19 by tde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/check/ft_checkmap.c \
		src/check/ft_mapflood.c \
		src/check/ft_verifications.c \
		src/error/errors.c \
		src/init/ft_init_data.c \
		src/init/ft_initgraph.c \
		src/init/ft_moves.c \
		src/main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

NAME = so_long
LIBFT		= libft.a
LIBFT_DIR := ./libft
LIBFT_LIB := $(LIBFT_DIR)/$(LIBFT)
CC = cc
FLAGS = -Wall -Wextra -Werror
OTHER = -lXext -lX11
MLXDIR = ./minilibx-linux/
MLX		= libmlx_Linux.a
RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS) $(MLX)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_LIB) $(MLXDIR)$(MLX) $(OTHER) -o $(NAME)

debug: $(OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) -g $(SRCS) $(LIBFT_LIB) $(MLXDIR)$(MLX) $(OTHER) -o $(NAME)

$(MLX):
			cd $(MLXDIR) && $(MAKE)

$(LIBFT_LIB):
	@cd $(LIBFT_DIR) && $(MAKE)

clean:
	cd $(LIBFT_DIR) && $(MAKE) clean
	$(RM) $(OBJS) $(BNS_OBJS)

fclean: clean
	cd $(LIBFT_DIR) && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all
