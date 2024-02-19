CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
NAME = ex04

all : $(NAME)

$(NAME) : $(SRC)
	$(CPP) $(SRC) $(CPPFLAGS) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all