# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 15:13:12 by mboukaiz          #+#    #+#              #
#    Updated: 2024/02/13 15:28:29 by mboukaiz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = PhoneBook.cpp Contact.cpp main.cpp
HEADER = PhoneBook.hpp Contact.hpp
NAME = PhoneBook

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all