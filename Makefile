CC=cc
CFLAGS=-Wall -Wextra -Werror -I include -g
NAME=libftprintf.a
SRC=ft_printf.c parse.c buffer.c eval.c eval_utils.c specifier_checks.c prefix.c tag.c eval/char.c eval/hex.c eval/int.c eval/str.c eval/unsigned.c math/math.c
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

compile: $(OBJ) main.o libft/libft.a
	$(CC) $(CFLAGS) $^

test: compile
	./a.out

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

.PHONY:
	all bonus clean fclean re compile test