#include "Point.hpp"

Fixed sign (Point p1, Point p2, Point p3)
{
	std::cout << p1.getX() << p1.getY() << std::endl;
	std::cout << p2.getX() << p2.getY() << std::endl;
	std::cout << p3.getX() << p3.getY() << std::endl;
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p1.getX() - p3.getX()) * (p2.getY() - p3.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1, d2, d3;
    bool has_neg, has_pos;

	std::cout << a.getX() << a.getY() << std::endl;
	std::cout << b.getX() << b.getY() << std::endl;
	std::cout << c.getX() << c.getY() << std::endl;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);

	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}
