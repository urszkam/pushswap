LIB_DIR 	= ./libft
LIBFT 		= libft.a
LIB_PATH	= ${LIB_DIR}/${LIBFT}

OUT_NAME	= push_swap
SRCS		= main.c utils.c utils2.c print_bench.c \
			sort_complex.c sort_medium.c sort_simple.c
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
