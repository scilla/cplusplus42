#include "Fixed.hpp"
#include <bitset>
#include <iostream>
#include <bitset>
#include <climits>
#include <iomanip>

template<typename T>
void show_binrep(const T& a)
{
    const char* beg = reinterpret_cast<const char*>(&a);
    const char* end = beg + sizeof(a);
    while(beg != end)
        std::cout << std::bitset<CHAR_BIT>(*--end) << ' ';
    std::cout << '\n';
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	rawBits = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Integer constructor called" << std::endl;
	rawBits = (n << binaryPoint) | (*(unsigned char *)(&n) >> 7);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called " << std::endl;
	rawBits = roundf(n * (1 << binaryPoint));
	/*
	int sign = *(unsigned int *)(&n) >> 31;
	int exponent = ((unsigned char)((*(unsigned int *)(&n) << 1) >> 24)) - 127;
	unsigned int mantissa = (*(unsigned int *)(&n) << 9) >> 9;
	mantissa += 0x800000;
	rawBits = mantissa >> ((23 - binaryPoint) - exponent);
	if (sign)
		rawBits *= -1;
	*/
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	rawBits = fixed.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return rawBits;
}

void Fixed::setRawBits( int const raw ) {
	rawBits = raw;
}

float Fixed::toFloat( void ) const {
	return ((float)rawBits / (1 << binaryPoint));
	/*
	unsigned int res = 0;
	unsigned int sign = *(unsigned int *)(&rawBits) >> 31;
	unsigned char rawExp = 23 - binaryPoint + 127 + 7;
	unsigned int rawCpy = rawBits;
	while (rawExp > (23 - binaryPoint + 127) - 32) {
		rawCpy = rawCpy << 1;
		if (rawCpy & (unsigned int)0x80000000) {
			break ;
		}
		rawExp--;
	}
	res += sign * (unsigned int)0x80000000;
	res += (unsigned int)rawExp * (unsigned int)0x800000;
	rawCpy = (unsigned int)(rawCpy >> 8) & 0x7FFFFF;
	res += rawCpy;
	return *((float *)&res);
	*/
}

int Fixed::toInt( void ) const {
	return (rawBits >> binaryPoint);
}

std::ostream& operator<< (std::ostream &out, Fixed const& c)
{
  return out << c.toFloat();
}