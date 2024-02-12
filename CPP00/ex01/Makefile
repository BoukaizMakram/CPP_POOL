# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 15:13:12 by mboukaiz          #+#    #+#              #
#    Updated: 2024/02/11 15:13:52 by mboukaiz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
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