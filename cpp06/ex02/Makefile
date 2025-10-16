NAME = realtype
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++11 -MMD -MP
SRC = main.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEP)

clean:

	rm -rf $(OBJ_DIR)

fclean: clean

	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re