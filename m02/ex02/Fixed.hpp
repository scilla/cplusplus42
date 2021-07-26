#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int rawBits;
	static const char binaryPoint = 6;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &fixed);
	Fixed& operator= (const Fixed &fixed);
	Fixed& operator++ (const Fixed &fixed);
	Fixed& operator* (const Fixed &fixed);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<< (std::ostream &out, Fixed const& c);

#endif