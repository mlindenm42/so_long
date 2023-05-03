# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 14:23:04 by mlindenm          #+#    #+#              #
#    Updated: 2023/05/02 19:52:17 by mlindenm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

SRC			=	sources/main.c sources/map_check.c sources/map_init.c sources/map_read.c sources/map_valid_path.c sources/map_visualize.c sources/textures_set.c sources/keyhook.c
OBJ			=	$(SRC:.c=.o)

MLX_PATH	=	libraries/MLX42
MLX			=	$(MLX_PATH)/build/libmlx42.a
MLX_FLAGS	=	-lglfw -L ~/.brew/Cellar/glfw/3.3.8/lib

LIBFT_PATH	=	libraries/libft
LIBFT		=	$(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_FLAGS) $(LIBFT) -Wno-gnu-include-next -I./LeakSanitizer/include -L./LeakSanitizer -llsan -lc++ -o $(NAME)

$(MLX):	$(MLX_PATH)
	cd $(MLX_PATH); cmake -B build; cmake --build build -j4

$(LIBFT): $(LIBFT_PATH)
	make -C $(LIBFT_PATH)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(MLX_PATH)/build;
	@make fclean -C $(LIBFT_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
