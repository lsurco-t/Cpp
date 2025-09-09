NAME = Megaphone
CC = C++
CFLAGS = -Wall -Werror -Wextra
SRC = Megaphone.cpp
OBJ = $(SRC)%.cpp:.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME)

clean:

	rm -f $(OBJ)

fclean: clean

	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re