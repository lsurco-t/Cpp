NAME = realtype
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++11 -MMD -MP
SRC = main.cpp Base.cpp functions.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

-include $(DEP)

clean:

	rm -rf $(OBJ_DIR)

fclean: clean

	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re