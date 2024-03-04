NAME = ex01
SRCS = SRCS/Animal.cpp SRCS/Dog.cpp SRCS/Cat.cpp SRCS/WrongCat.cpp SRCS/WrongAnimal.cpp SRCS/Brain.cpp SRCS/main.cpp
HDRS = HDRS/Animal.hpp HDRS/Dog.hpp HDRS/Cat.hpp HDRS/WrongCat.hpp HDRS/WrongAnimal.hpp HDRS/Brain.hpp

CPP = c++
CPF = -Wall -Wextra -Werror -std=c++98

all		: $(NAME)

$(NAME)	: $(HDRS) $(SRCS)
	$(CPP) $(CPF) $(SRCS) -o $(NAME)

clean	:
	rm -rf $(NAME)

fclean	: clean

re		: fclean all