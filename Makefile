# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 16:38:19 by tmatis            #+#    #+#              #
#    Updated: 2021/01/09 13:15:23 by tmatis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= cub3d

.c.o:
			@echo Compiling: $<
			@gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

$(NAME):	${OBJS_LIBFT} ${OBJS_PRINTF}
			@echo Linking library...
			@gcc -Wall -Wextra -Werror $@ ${OBJS_CUB}

all:		${NAME}

clean:
			@echo CLeaning OBJS and tests...
			@rm -f ${OBJS_LIBFT} ${OBJS_PRINTF} ${OBJS_TESTS} test

fclean:		clean
			@echo CLeaning library...
			@rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re 
