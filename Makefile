# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 16:38:19 by tmatis            #+#    #+#              #
#    Updated: 2021/02/04 14:46:45 by tmatis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= cub3d

SRCS_CUB3D	= main.c parser/parser.c parser/parse_head.c parser/parse_map.c \
			  parser/free_scene.c parser/elem_parse.c parser/check_head.c \
			  parser/check_map.c parser/map_utils.c graphic/graphic.c\
			  graphic/render.c graphic/rgb.c graphic/events.c \
			  graphic/raycaster.c graphic/move.c graphic/image.c \
			  graphic/init.c parser/parse_sprite.c graphic/sprite.c \
			  graphic/raycaster_utils.c bitmap/bitmap.c


OBJS_CUB3D	= $(addprefix srcs/, ${SRCS_CUB3D:.c=.o})

OBJS_BONUS	= $(addprefix srcs_bonus/, ${SRCS_CUB3D:.c=.o})

.c.o:
			@echo Compiling: $<
			@clang -Wall -Wextra -Werror -g -c $< -o ${<:.c=.o}

$(NAME):	libft mlx ${OBJS_CUB3D}
			@echo Linking program...
			@clang -Wall -Wextra -Werror -g -o $@ ${OBJS_CUB3D} -lXext -lX11 -lm -L./libft -lft -L./minilibx-linux -lmlx
mlx:
			@echo Compling mlx...
			@make -sC ./minilibx-linux

libft:
			@echo compiling libft...
			@make -sC ./libft libft.a

all:		$(NAME)

clean:
			@echo CLeaning OBJS and tests...
			@make -sC ./libft fclean
			@make -sC ./minilibx-linux clean
			@rm -f ${OBJS_CUB3D} ${OBJS_BONUS}

fclean:		clean
			@echo CLeaning program...
			@rm -f ${NAME}

bonus:		libft mlx ${OBJS_BONUS}
			@echo Linking program...
			@clang -Wall -Wextra -Werror -g -o ${NAME} ${OBJS_BONUS} -lXext -lX11 -lm -L./libft -lft -L./minilibx-linux -lmlx

re:			fclean all

.PHONY:		all clean fclean re libft mlx 
