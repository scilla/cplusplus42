#ifndef SPAN_HPP
#define SPAN_HPP
# include <exception>
# include <algorithm>
# include <array>
# include <vector>
# include <iostream>

class Span
{
private:
	const unsigned int _size;
public:
	unsigned int _ind;
	std::vector<int> _array;
	Span(unsigned int n);
	Span(const Span& s);
	Span& operator= (const Span& s);
	~Span();
	void addNumber(int i);
	unsigned int shortestSpan() /*const*/;
	unsigned int longestSpan() /*const*/;
	class FullArrayException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class ImpossibleSpanException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	unsigned int getSize() const;
};

const char* Span::FullArrayException::what() const throw() {
	return "Array is already full";
}

const char* Span::ImpossibleSpanException::what() const throw() {
	return "Not enough elements in array";
}

void Span::addNumber(int i) {
	if (getSize() == _ind)
		throw FullArrayException();
	_ind++;
	_array.push_back(i);
	std::cout << "Added: " << i << std::endl;
}

unsigned int Span::shortestSpan() /*const*/ {
	if (_ind < 2)
		throw ImpossibleSpanException();
	unsigned int *res = new unsigned int;
	*res = std::numeric_limits<unsigned int>::max();
	std::vector<int> cpy(_array);
	std::sort(cpy.begin(), cpy.end());
	for (std::vector<int>::iterator it = cpy.begin(); it != cpy.begin() + _ind - 1; it++) {
		if (*res > static_cast<unsigned int>(*(it + 1) - *it))
			*res = *(it + 1) - *it;
	}
	return *res;
}

unsigned int Span::longestSpan() /*const*/ {
	if (_ind < 2)
		throw ImpossibleSpanException();
	return *(std::max_element(_array.begin(), _array.end())) - *(std::min_element(_array.begin(), _array.end()));
}


unsigned int Span::getSize() const {
	return _size;
}

Span::Span(unsigned int n): _size(n)
{
	_ind = 0;
}

Span::Span(const Span& s): _size(s.getSize())
{
	*this = s;
}

Span& Span::operator= (const Span& s)
{
	_array = s._array;
	_ind = s._ind;
	// for (std::vector<int>::iterator it = s._array.begin(); it != s._array.end(); it++) {
	// 	_array.push_back(*it);
	// }
	return *this;
}

Span::~Span()
{
}

#endif /* SPAN_HPP */
