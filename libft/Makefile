NAME = libft.a
SRCS =	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_strncmp.c ft_strlen.c ft_memmove.c \
	ft_strlcat.c ft_strlcpy.c ft_strrchr.c ft_bzero.c ft_split.c \
	ft_strchr.c ft_memset.c ft_memcpy.c ft_memcmp.c ft_itoa.c \
	ft_memchr.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_strtrim.c \
	ft_atoi.c ft_striteri.c ft_strjoin.c ft_strmapi.c ft_substr.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstmap.c \
	ft_lstnew.c ft_lstsize.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
	ft_printf.c put_c.c put_n.c put_p.c put_s.c put_x.c
OBJS = ${SRCS:.c=.o}
HEADER_DIR = ./
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${NAME}

%.o: %.c
	@cc -c ${CFLAGS} -I ${HEADER_DIR} $^ -o $@

${NAME}: ${OBJS}
	@ar rcs ${NAME} $^
clean:
	@${RM} ${OBJS}
fclean: clean
	@${RM} ${NAME}
re: fclean all

tests:
	@cc ${CFLAGS} -o tests.out .tests.c -L. -lft -I./
	@touch endl.txt nbr.txt str.txt char.txt
	@./tests.out
	@rm -f tests.out *.txt

bsd_tests:
	@cc ${CFLAGS} -o bsd_tests.out .bsd_tests.c -L. -lft -I./ -lbsd
	valgrind --leak-check=full --show-leak-kinds=all ./bsd_tests.out
	@rm -f bsd_tests.out

memory_leaks:
	@cc ${CFLAGS} -o tests.out .tests.c -L. -lft -I./
	@touch endl.txt nbr.txt str.txt char.txt
	valgrind --leak-check=full --show-leak-kinds=all ./tests.out
	@rm -f tests.out *.txt

tclean:
	@rm -f *.txt

bonus_tests:
	@cc ${CFLAGS} -o bonus_tests.out .bonus_tests.c -L. -lft -I./
	valgrind --leak-check=full --show-leak-kinds=all ./bonus_tests.out
	@rm -f bonus_tests.out *.txt

.PHONY: all clean fclean re bonus bonus_tests bsd_tests tests
