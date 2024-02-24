#include "fixed.hpp"

Fixed::Fixed() : fixed_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other) 
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->fixed_value = other.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits() const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_value);
}

void	Fixed::setRawBits( int const raw ) 
{
	std::cout << "getRawBits member function called" << std::endl;
	this->fixed_value = raw;
}