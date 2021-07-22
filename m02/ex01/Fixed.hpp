#ifndef FICED_HPP
# define FICED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int rawBits;
	static const char binaryPoint = 8;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed &fixed);
	Fixed& operator= (const Fixed &fixed);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif

/*
cFloat 8
0001 0100
fFloat 4
1000 0000

*/