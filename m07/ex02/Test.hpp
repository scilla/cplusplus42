#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

class Test {
public:
	Test() { _n = 1; }
	Test(int n) : _n(n) { }

	int	getN() const { return (_n); }

private:
	int	_n;
};

std::ostream&	operator<<(std::ostream& os, const Test& obj)
{
	os << obj.getN();
	return (os);
}


#endif /* TEST_HPP */
