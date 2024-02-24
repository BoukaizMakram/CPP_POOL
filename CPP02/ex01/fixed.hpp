#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixed_value;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int int_value);
		Fixed(const float float_value);
		~Fixed();
		float	toFloat( void ) const;
		int		toInt( void ) const;
		Fixed&	operator=(const Fixed& other);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif