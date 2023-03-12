CC=cc
CFLAGS=-Wall -Wextra -Werror -I include -I libft -g
NAME=libftprintf.a
SRC=eval/char.c eval/hex.c eval/int.c eval/str.c eval/unsigned.c process/apply.c process/parse.c process/run.c src/ft_printf.c utils/buffer.c utils/checks.c utils/checks2.c utils/checks3.c utils/eval.c utils/flags.c utils/flags2.c utils/malloc.c utils/math.c utils/prefix.c utils/str.c utils/str2.c utils/tag.c
OBJ=$(SRC:.c=.o)
LIBFT=libft/libft.a
HEADERS=libft/libft.h

all: $(NAME)

%.o: %.c $(HEADERS) $(LIBFT) Makefile
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT):
	(cd libft && make && make clean)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $@
	ar -crs $@ $(OBJ)

# bonus: all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

compile: $(LIBFT) $(OBJ) main.o
	$(CC) $(CFLAGS) $^

test: compile
	./a.out

tclean: clean
	rm -f main.o

tfclean: tclean
	rm -f a.out

.PHONY:
	all bonus clean fclean re compile test tclean
