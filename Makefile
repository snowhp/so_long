# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-sous <tde-sous@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 16:21:48 by tde-sous          #+#    #+#              #
#    Updated: 2023/04/12 16:26:13 by tde-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/check/ft_checkmap.c \
		src/error/errors.c \
		src/init/ft_init_data.c \
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
RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) -Wall -Wextra -Werror $(OBJS) $(LIBFT_LIB) -o $(NAME)

debug: $(OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) -g $(SRCS) $(LIBFT_LIB) -o $(NAME)
	
$(LIBFT_LIB):
	@cd $(LIBFT_DIR) && $(MAKE)

clean:
	cd $(LIBFT_DIR) && $(MAKE) clean
	$(RM) $(OBJS) $(BNS_OBJS)

fclean: clean
	cd $(LIBFT_DIR) && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all