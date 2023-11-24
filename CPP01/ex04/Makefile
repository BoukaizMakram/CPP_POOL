CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
NAME = ex04

all : $(NAME)

$(NAME) : $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all