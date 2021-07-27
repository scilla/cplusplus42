#ifndef FIXED_HPP
# define FIXED_HPP

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
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	Fixed operator +(const Fixed &b) const;
	Fixed operator -(const Fixed &b) const;
	Fixed operator *(const Fixed &b) const;
	Fixed operator /(const Fixed &b) const;
	bool operator ==(const Fixed &b) const;
	bool operator !=(const Fixed &b) const;
	bool operator <(const Fixed &b) const;
	bool operator <=(const Fixed &b) const;
	bool operator >(const Fixed &b) const;
	bool operator >=(const Fixed &b) const;
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(Fixed const &a, Fixed const &b);
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(Fixed const &a, Fixed const &b);
};

std::ostream& operator<< (std::ostream &out, Fixed const& c);

#endif
