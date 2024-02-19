CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Harl.cpp
HEADER = Harl.hpp
NAME = ex05

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all