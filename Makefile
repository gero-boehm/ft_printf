CC=cc
CFLAGS=-Wall -Wextra -Werror -I include
NAME=libftprintf.a
SRC=ft_printf.c parse.c buffer.c eval.c eval_utils.c specifier_checks.c prefix.c
OBJ=$(SRC:.c=.o)
INCLUDES=include/ft_printf.h libft/libft.h

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

libft/libft.a :
	(cd libft && make && make clean)

$(NAME): $(OBJ) | libft/libft.a
	cp libft/libft.a $@
	ar -crs $@ $^

bonus: all

test: $(OBJ) main.o libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^ && ./test

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all bonus clean fclean re test