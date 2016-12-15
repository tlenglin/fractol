# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:23:56 by tlenglin          #+#    #+#              #
#    Updated: 2016/12/14 18:42:57 by tlenglin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = display.c events_manager.c keyboard_event1.c keyboard_event2.c fractol.c sequences_mj.c sequences_n.c ft_color_mj.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FLAGSMLX = -I/usr/local/include/mlx.h -lmlx -framework OpenGL -framework Appkit

CC = gcc

LIBFT_PATH = ./libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L./libft -lft $(FLAGSMLX)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
