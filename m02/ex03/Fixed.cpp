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
	rawBits = 0;
}

Fixed::Fixed(const int n)
{
	rawBits = (n << binaryPoint) | (*(unsigned char *)(&n) >> 7);
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called " << std::endl;
	int sign = *(unsigned int *)(&n) >> 31;
	int exponent = ((unsigned char)((*(unsigned int *)(&n) << 1) >> 24)) - 127;
	unsigned int mantissa = (*(unsigned int *)(&n) << 9) >> 9;
	mantissa += (1 << 23);
	int shift = ((23 - binaryPoint) - exponent);
	if (shift > 0)
		rawBits = mantissa >> shift;
	else if (shift < 0)
		rawBits = mantissa << -shift;
	if (sign)
		rawBits *= -1;
	if (shift > 0 && (mantissa & (1 << (shift - 1))))
		rawBits++;
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
	rawBits = fixed.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed &fixed)
{
	this->setRawBits(fixed.getRawBits());
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
	return (rawBits == b.rawBits);
}

bool Fixed::operator !=(const Fixed &b) const {
	return (rawBits != b.rawBits);
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
	temp.setRawBits(((rawBits) * (b.rawBits)) >> 8);
	return temp;
}

Fixed Fixed::operator /(const Fixed &b) const {
	Fixed temp((rawBits / (float)b.rawBits) * (1 << 8));
	return temp;
}

bool Fixed::operator > (const Fixed &b) const {
	return (rawBits > b.rawBits >> (b.binaryPoint - binaryPoint));
}

bool Fixed::operator >= (const Fixed &b) const {
	return (rawBits >= b.rawBits >> (b.binaryPoint - binaryPoint));
}

bool Fixed::operator < (const Fixed &b) const {
	return (rawBits < b.rawBits >> (b.binaryPoint - binaryPoint));
}

bool Fixed::operator <= (const Fixed &b) const {
	return (rawBits <= b.rawBits >> (b.binaryPoint - binaryPoint));
}

Fixed::~Fixed()
{
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
	unsigned int rawCpy = rawBits;
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
