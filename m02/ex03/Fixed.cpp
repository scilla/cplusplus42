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
	rawBits = roundf(n * (1 << binaryPoint));
}

Fixed& Fixed::operator= (const Fixed &fixed)
{
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
	temp.setRawBits(((rawBits) * (b.rawBits)) >> 8);
	return temp;
}

Fixed Fixed::operator /(const Fixed &b) const {
	Fixed temp((rawBits / (float)b.rawBits) * (1 << 8));
	return temp;
}

bool Fixed::operator > (const Fixed &b) const {
	if (binaryPoint > b.binaryPoint)
		return (rawBits >> (binaryPoint - b.binaryPoint) > b.rawBits);
	else
		return (rawBits > b.rawBits >> (b.binaryPoint - binaryPoint));
}

bool Fixed::operator >= (const Fixed &b) const {
	if (binaryPoint > b.binaryPoint)
		return (rawBits >> (binaryPoint - b.binaryPoint) >= b.rawBits);
	else
		return (rawBits >= b.rawBits >> (b.binaryPoint - binaryPoint));
}

bool Fixed::operator < (const Fixed &b) const {
	if (binaryPoint > b.binaryPoint)
		return (rawBits >> (binaryPoint - b.binaryPoint) < b.rawBits);
	else
		return (rawBits < b.rawBits >> (b.binaryPoint - binaryPoint));
}

bool Fixed::operator <= (const Fixed &b) const {
	if (binaryPoint > b.binaryPoint)
		return (rawBits >> (binaryPoint - b.binaryPoint) <= b.rawBits);
	else
		return (rawBits <= b.rawBits >> (b.binaryPoint - binaryPoint));
}

Fixed::Fixed(const Fixed &fixed)
{
	this->setRawBits(fixed.getRawBits());
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
	return ((float)rawBits / (1 << binaryPoint));
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
