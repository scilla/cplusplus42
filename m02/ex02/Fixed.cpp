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
	rawBits = 0;
	unsigned int mantissa;
	int shift;
	std::cout << "Float constructor called " << std::endl;
	unsigned int sign = (*(unsigned int *)(&n) & (1 << 31));
	int exponent = (unsigned char)((*(unsigned int *)(&n) << 1) >> 24);
	if (!exponent) {
		exponent = 0;
		mantissa = 0;
		shift = 0;
	} else {
		exponent -= 127;
		mantissa = (*(unsigned int *)(&n) << 9) >> 9;
		mantissa += (1 << 23);
		shift = ((23 - binaryPoint) - exponent);
	}
	if (shift > 0)
		rawBits = mantissa >> shift;
	else if (shift < 0)
		rawBits = mantissa << -shift;
	if (sign)
		rawBits = rawBits | (unsigned int)(1 << 31);
	if (shift > 0 && (mantissa & (1 << (shift - 1))))
		rawBits++;
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	rawBits = fixed.getRawBits();
	return *this;
}


Fixed& Fixed::operator++() {
	rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed& Fixed::operator--() {
	rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--*this;
	return temp;
}

bool Fixed::operator ==(const Fixed &b) const {
	return (rawBits == b.rawBits && binaryPoint == b.binaryPoint);
}

bool Fixed::operator !=(const Fixed &b) const {
	return (rawBits != b.rawBits ||  binaryPoint != b.binaryPoint);
}

Fixed Fixed::operator +(const Fixed &b) const {
	Fixed temp;
	temp.setRawBits(rawBits + b.rawBits);
	return temp;
}

Fixed Fixed::operator -(const Fixed &b) const {
	Fixed temp;
	temp.setRawBits(rawBits - b.rawBits);
	return temp;
}

Fixed Fixed::operator *(const Fixed &b) const {
	Fixed temp;
	temp.setRawBits(((rawBits >> 0) * (b.rawBits >> 0)) >> 8);
	return temp;
}

Fixed Fixed::operator /(const Fixed &b) const {
	Fixed temp(this->toFloat() / b.toFloat());
	return temp;
}

bool Fixed::operator > (const Fixed &b) const {
	return (rawBits > b.rawBits);
}

bool Fixed::operator >= (const Fixed &b) const {
	return (rawBits >= b.rawBits);
}

bool Fixed::operator < (const Fixed &b) const {
	return (rawBits < b.rawBits);
}

bool Fixed::operator <= (const Fixed &b) const {
	return (rawBits <= b.rawBits);
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
	unsigned int res = 0;
	unsigned int sign = *(unsigned int *)(&rawBits) >> 31;
	unsigned char rawExp = 23 - binaryPoint + 127 + 7;
	unsigned int rawCpy = *(unsigned int *)(&rawBits);
	if (sign)
		rawCpy -= 1 << 31;
	if (rawCpy == 0)
		return 0;
	if (rawCpy == (unsigned int)(1 << 23))
		return -0;
	while (rawExp > (23 - binaryPoint + 127) - 32) {
		rawCpy = rawCpy << 1;
		if (rawCpy & (1 << 31)) {
			break ;
		}
		rawExp--;
	}
	res += sign * (1 << 31);
	res += (unsigned int)rawExp * (1 << 23);
	rawCpy = (unsigned int)(rawCpy >> 8) & 0x7FFFFF;
	res += rawCpy;
	return *((float *)&res);
}

int Fixed::toInt( void ) const {
	return (rawBits >> binaryPoint);
}

std::ostream& operator<< (std::ostream &out, Fixed const& c)
{
  return out << c.toFloat();
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a.getRawBits() > b.getRawBits() ? a: b);
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b) {
	return (a.getRawBits() > b.getRawBits() ? a: b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a.getRawBits() > b.getRawBits() ? b: a);
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b) {
	return (a.getRawBits() > b.getRawBits() ? b: a);
}
