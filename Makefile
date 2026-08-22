# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pausulzy <pausulzy@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/17 15:10:56 by pausulzy          #+#    #+#              #
#    Updated: 2026/08/18 10:07:11 by pausulzy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR 	= ./libft
LIBFT 		= libft.a
LIB_PATH	= ${LIB_DIR}/${LIBFT}

OUT_NAME	= push_swap
SRCS		= main.c utils.c sort_utils.c print_bench.c sort_complex.c \
			sort_medium.c sort_simple.c push.c swap.c rotate.c \
			rotate_reverse.c complex_sort_utils.c validate_list.c
OBJS		= ${SRCS:.c=.o}
HEADER_DIR	= ./
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I ${HEADER_DIR} -I ${LIB_DIR}

%.o: %.c
	@cc -c ${CFLAGS} ${CPPFLAGS} $< -o $@

all: ${LIB_PATH} ${OUT_NAME}

$(LIB_PATH):
	@$(MAKE) --no-print-directory -C $(LIB_DIR)

${OUT_NAME}: ${LIB_PATH} ${OBJS}
	@cc ${OBJS} ${LIB_PATH} -o ${OUT_NAME}

clean:
	@$(MAKE) --no-print-directory -C ${LIB_DIR} clean
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${OUT_NAME}
	@$(MAKE) --no-print-directory -C ${LIB_DIR} fclean

re: fclean all

.PHONY: all clean fclean re
