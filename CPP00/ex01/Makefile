# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 15:13:12 by mboukaiz          #+#    #+#              #
#    Updated: 2024/02/12 18:27:37 by mboukaiz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98
CPPFLAGS = -Iinclude

SRC = phone.cpp
HEADER = PhoneBook.hpp Contact.hpp
NAME = PhoneBook

all : $(NAME)

$(NAME) : $(SRC) $(HEADER)
	$(CXX) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all