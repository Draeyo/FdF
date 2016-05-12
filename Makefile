NAME = FdF

SRCS = $(wildcard srcs/*.c)

OBJ = $(SRC:.c=.o)

INC = includes/

all: $(NAME)

$(NAME): $(OBJ)
	@(gcc -o $(NAME) $(OBJ))
	@(echo "$(NAME) created");

%.o: %.c
	@(gcc -c $< -o $@ -lmlx -framework OpenGL -framework AppKit -I $(INC) -L.)
	@(echo "Binary files updated.")

clean:
	@(/bin/rm -f $(OBJ))
	@(echo "Binary files deleted.")

fclean: clean
	@(/bin/rm -f $(NAME))
	@(echo "$(NAME) deleted.")

re: fclean all

