#include "fixed.hpp"

Fixed::Fixed() : fixed_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//A constructor that takes a constant integer as a parameter.
Fixed::Fixed(const int intValue)
{
	fixed_value = intValue << fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

//A constructor that takes a constant floating-point number as a parameter.
Fixed::Fixed(const float floatValue)
{
	fixed_value = roundf(floatValue * ( 1 << fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

//A member function float toFloat( void ) const;
float Fixed::toFloat() const
{
	return (fixed_value + 0.0) / (1 << fractionalBits);
}

//A member function int toInt( void ) const;
int Fixed::toInt() const
{
	return (fixed_value >> fractionalBits);
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
	return (this->fixed_value);
}

void	Fixed::setRawBits( int const raw ) 
{
	this->fixed_value = raw;
}


//An overload of the insertion («) operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) 
{
	os << fixed.toFloat();
	return (os);
}
