/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukaiz <mboukaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:12:40 by mboukaiz          #+#    #+#             */
/*   Updated: 2024/02/11 15:13:57 by mboukaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Car
{
public:
	std::string	brand;
	Car (std::string x) : brand(x)
	{

	}
	~Car ()
	{
		std::cout << "done!" << std::endl; 
	}
	// void set(std::string brand)
	// {
	// 	this->brand = brand;
	// }
	void displayCar() const
	{
		std::cout << brand << std::endl;
	}
};

int	main()
{
	Car chev("Cheverol");
	Car chev2("Cheverolet");

	std::string Car::*ptr = &Car::brand;

	std::cout << chev2.*ptr << std::endl;
	return (0);
}