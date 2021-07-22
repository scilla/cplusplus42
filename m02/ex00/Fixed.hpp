#ifndef FICED_HPP
# define FICED_HPP

# include <iostream>

class Fixed
{
private:
	int rawBits;
	static const char binaryPoint = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed& operator= (const Fixed &fixed);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif