#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(Fixed const x, Fixed const y);
	Point(Point const &point);
	Point& operator= (const Point &point);
	~Point();
	Fixed getX() const;
	Fixed getY() const;
	void setX(Fixed const x);
	void setY(Fixed const y);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
