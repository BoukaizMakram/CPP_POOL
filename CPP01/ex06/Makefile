CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Harl.cpp
HEADER = Harl.hpp
NAME = harlFilter

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all