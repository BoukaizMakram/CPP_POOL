CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++98
CPPFLAGS = -Iinclude

SRC = phone.cpp
HEADER = phone.hpp PhoneBook.hpp Contact.hpp
NAME = phone

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CXX) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all