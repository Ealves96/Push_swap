# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealves <ealves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 16:45:51 by elie              #+#    #+#              #
#    Updated: 2023/05/24 17:53:26 by ealves           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

LIBFT			=	includes/libft/libft.a

PRINTF			=	includes/ft_printf/libftprintf.a

SRCS			=	main.c parsing_utils.c parsing_utils2.c parsing_mouv1.c parsing_mouv2.c \
					algo.c algo2.c

OBJS			=	${SRCS:.c=.o}

HEAD			=	-I includes

CFLAGS			=	-Wall -Werror -Wextra -D BENCH=0 -g3

all				:	${NAME}

.c.o	:
		@cc  ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	@make -C includes/libft
	@make -C includes/ft_printf
	cc $(OBJS) ${LIBFT} ${GNL} ${PRINTF} -o $(NAME) #-fsanitize=address

${OBJS} : ${SRCS}
	cc ${CFLAGS} ${HEAD} -c ${SRCS}

clean			:
					make clean -C includes/libft/
					make clean -C includes/ft_printf/
					rm -rf ${OBJS}

fclean			:	clean
					make fclean -C includes/libft/
					make fclean -C includes/ft_printf/
					rm -rf ${LIBFT}
					rm -rf ${PRINTF}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re
