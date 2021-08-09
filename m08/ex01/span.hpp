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
	std::vector<int> _array;
	Span(unsigned int n);
	Span(const Span& s);
	Span& operator= (const Span& s);
	~Span();
	void addNumber(int i);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
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
	if (_array.size() == _size)
		throw FullArrayException();
	_array.push_back(i);
}

unsigned int Span::shortestSpan() const {
	unsigned int *res = new unsigned int;
	res = NULL;
	std::vector<int> cpy(_array);
	std::sort(cpy.begin(), cpy.end());
	for (std::vector<int>::iterator it = cpy.begin(); it != cpy.end() - 1; it++) {
		if (!res || *res > static_cast<unsigned int>(*(it + 1) - *it))
			*res = *(it + 1) - *it;
	}
	return *res;
}

unsigned int Span::longestSpan() const {
	std::vector<int> cpy(_array);
	std::sort(cpy.begin(), cpy.end());
	return *(cpy.end() -1) - *cpy.begin();
}


unsigned int Span::getSize() const {
	return _size;
}

Span::Span(unsigned int n): _size(n)
{
}

Span::Span(const Span& s): _size(s.getSize())
{
	*this = s;
}

Span& Span::operator= (const Span& s)
{
	_array = s._array;
	// for (std::vector<int>::iterator it = s._array.begin(); it != s._array.end(); it++) {
	// 	_array.push_back(*it);
	// }
	return *this;
}

Span::~Span()
{
}

#endif /* SPAN_HPP */
