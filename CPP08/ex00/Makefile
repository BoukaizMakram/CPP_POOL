NAME		=	ex00
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC_FILES	=	main.cpp
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)
HDR_FILES	=	easyfind.hpp

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.cpp $(HDR_FILES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all