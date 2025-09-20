NAME = hithisisbrain
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++11
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:

	rm -f $(OBJ)

fclean: clean

	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re