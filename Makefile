# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 21:12:19 by azkaraka          #+#    #+#              #
#    Updated: 2025/12/16 21:12:21 by azkaraka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(MLX_PATH)

# MiniLibX
MLX_PATH	= minilibx_mms_20191025_beta/
MLX_NAME	= libmlx.dylib
MLX			= $(MLX_PATH)$(MLX_NAME)
MLX_FLAGS	= -L$(MLX_PATH) -lmlx -framework Cocoa -framework Metal -framework MetalKit

SRCS		= main.c init.c render.c events.c math_utils.c string_utils.c
OBJS		= $(SRCS:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	@make -C $(MLX_PATH)
	@cp $(MLX_PATH)libmlx.dylib .

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME) libmlx.dylib

re: fclean all

.PHONY: all clean fclean re