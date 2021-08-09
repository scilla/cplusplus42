#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include <iterator>
# include <exception>
# include <deque>
# include <array>

class ElementNotFound: public std::exception
{
public:
	virtual const char* what() const throw();
};

template<typename T>
typename T::iterator easyfind(T& v, int n) {
	typename T::iterator location;
	location = std::find( v.begin(), v.end(), n );
	if (location == v.end())
		throw ElementNotFound();
	return location;
}

#endif /* EASYFIND_HPP */
