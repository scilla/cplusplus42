#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y)
{
}

void Point::setX(Fixed newx) {
	((Fixed)x).setRawBits(newx.getRawBits());
}

void Point::setY(Fixed newy) {
	((Fixed)y).setRawBits(newy.getRawBits());
}

Point::Point(const Point &point) {
	this->setX(point.getX());
	this->setY(point.getY());
}

Point& Point::operator= (const Point &point) {
	(Fixed)this->x = (Fixed const)point.getX();
	(Fixed)this->y = (Fixed const)point.getY();
	return *this;
}

Fixed Point::getX() const {
	return x;
}

Fixed Point::getY() const {
	return y;
}


Point::~Point()
{
}