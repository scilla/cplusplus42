#ifndef SPAN_HPP
#define SPAN_HPP
# include <exception>
# include <algorithm>
# include <array>
# include <vector>

class Span
{
private:
	const unsigned int _size;
	unsigned int _ind;
public:
	std::vector<int> _array;
	Span(unsigned int n);
	Span(Span& const s);
	Span& operator= (Span& const s);
	~Span();
	void addNumber(int i);
	unsigned int const shortestSpan() const;
	unsigned int const longestSpan() const;
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
	const unsigned int getSize() const;
};

const char* Span::FullArrayException::what() const {
	return "Array is already full";
}

const char* Span::ImpossibleSpanException::what() const {
	return "Not enough elements in array";
}

void Span::addNumber(int i) {
	if (_array.size() == _size)
		throw FullArrayException();
	_array.push_back(i);
}

const unsigned int Span::getSize() const {
	return _size;
}

Span::Span(unsigned int n): _size(n)
{
}

Span::Span(Span& const s): _size(s.getSize())
{
	*this = s;
}

Span& Span::operator= (Span& const s)
{
	for (std::vector<int>::iterator it = s._array.begin(); it != s._array.end(); it++) {
		_array.push_back(*it);
	}
	return *this;
}

Span::~Span()
{
}

#endif /* SPAN_HPP */
