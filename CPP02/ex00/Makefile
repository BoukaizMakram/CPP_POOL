NAME = ex00
SRCS = main.cpp fixed.cpp
HDRS = fixed.hpp
CPP  = c++
CPPFLAGS = -Wall -Werror -Werror -std=c++98

all     : $(NAME)

$(NAME) : $(SRCS) $(HDRS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

fclean  :
	rm -rf $(NAME)

clean  : fclean

re     : clean all