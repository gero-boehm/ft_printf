CC=cc
# CFLAGS=-Wall -Wextra -Werror
# CFLAGS=
NAME=libftprintf.a
MANDATORY_SRC=ft_printf.c parse.c buffer.c eval.c eval_utils.c $(wildcard libft/*.c)
MANDATORY_OBJ=$(MANDATORY_SRC:.c=.o)
# libft/ft_atoi.o libft/ft_bzero.o libft/ft_calloc.o libft/ft_isalnum.o libft/ft_isalpha.o libft/ft_isascii.o libft/ft_isdigit.o libft/ft_isprint.o libft/ft_itoa.o libft/ft_memchr.o libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memmove.o libft/ft_memset.o libft/ft_putchar_fd.o libft/ft_putendl_fd.o libft/ft_putnbr_fd.o libft/ft_putstr_fd.o libft/ft_split.o libft/ft_strchr.o libft/ft_strdup.o libft/ft_striteri.o libft/ft_strjoin.o libft/ft_strlcat.o libft/ft_strlcpy.o libft/ft_strlen.o libft/ft_strmapi.o libft/ft_strncmp.o libft/ft_strnstr.o libft/ft_strrchr.o libft/ft_strtrim.o libft/ft_substr.o libft/ft_tolower.o libft/ft_toupper.o
INCLUDES=include/ft_printf.h libft/libft.h

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(MANDATORY_OBJ) $(INCLUDES)
	ar -crs $(NAME) $^

bonus: $(MANDATORY_OBJ) $(BONUS_OBJ) $(INCLUDES)
	ar -crs $(NAME) $^

test: $(MANDATORY_OBJ) $(BONUS_OBJ) main.o
	$(CC) $(CFLAGS) -o $@ $^ && ./test

libft/libft.a :
	(cd libft && make && make clean)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY:
	all bonus clean fclean re