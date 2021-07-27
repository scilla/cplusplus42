#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y)
{
}

void Point::setX(Fixed newx) {
	((Fixed *)(&this->x))->setRawBits(newx.getRawBits());
}

void Point::setY(Fixed newy)
{
	((Fixed *)(&this->y))->setRawBits(newy.getRawBits());
}

Point::Point(const Point &point) : x(point.getX()), y(point.getY())
{
}

Point& Point::operator= (const Point &point) {
	this->setX(point.getX());
	this->setY(point.getY());
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