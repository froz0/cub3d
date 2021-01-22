# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 16:38:19 by tmatis            #+#    #+#              #
#    Updated: 2021/01/22 16:24:45 by tmatis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= cub3d

SRCS_CUB3D	= main.c parser/parser.c parser/parse_head.c parser/parse_map.c \
			  parser/free_scene.c parser/elem_parse.c parser/check_head.c \
			  parser/check_map.c parser/map_utils.c


OBJS_CUB3D	= $(addprefix srcs/, ${SRCS_CUB3D:.c=.o})



.c.o:
			@echo Compiling: $<
			@clang -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

$(NAME):	libft mlx ${OBJS_CUB3D}
			@echo Linking program...
			@clang -Wall -Wextra -Werror -o $@ ${OBJS_CUB3D} -L./libft -lft
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
			@rm -f ${OBJS_CUB3D}

fclean:		clean
			@echo CLeaning program...
			@rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re libft mlx 
