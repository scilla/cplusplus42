#include "iter.hpp"
#include <iostream>

class Awesome
{
private:
	int _n;
public:
	Awesome(void): _n(42) { return; }
	int get(void) const { return this->_n; }
};

std::ostream& operator<< (std::ostream& o, Awesome const& rhs) { 
	o << rhs.get();
	return o;
}

template<typename T>
void print(T const & x) {
	std::cout << x << std::endl;
	return;
}

int main() {
	int n[] = {10, 100, 88};
	float k[] = {0.0, 1.234, 4200.42};
	std::string s[] = {"bella pe me", "bella pe te", "bella pe tutti"};

	iter(n, 3, &print);
	iter(k, 3, &print);
	iter(s, 3, &print);

	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];

	iter(tab, 5, &print);
	iter(tab2, 5, &print);
	return 0;
}
