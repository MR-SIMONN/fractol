SRC = calculations.c drawing_it.c parsing.c utils.c main.c

NAME = fractol

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework AppKit -lmlx -lm

OBJ = $(SRC:.c=.o)

RM = rm -rf


all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(MLXFLAGS) $^ -o $@

%.o: %.c fractol.h
	cc $(CFLAGS) -c $<

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean
