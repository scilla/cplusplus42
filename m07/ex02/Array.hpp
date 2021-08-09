#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <stdio.h>
#include <iostream>

template<typename T>
class Array
{
public:
	Array<T>();
	Array<T>(unsigned int n);
	Array<T>(const Array& array);
	Array& operator= (const Array& array);
	T& operator[] (int i) const;
	~Array<T>();
	unsigned int size() const;
	class OutOfBoundException: public std::exception
	{
	public:
		virtual const char* what() const throw() ;
	};	
	
private:
	unsigned int _size;
	T* _array;
};

template<typename T>
const char* Array<T>::OutOfBoundException::what() const throw() {
	return ("OutOfBoundException");
}

template<typename T>
Array<T>::Array()
{
	_array = NULL;
	_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T [n];
	_size = n;
}

template<typename T>
Array<T>::Array(const Array<T>& array)
{
	_array = NULL;
	*this = array;
}

template<typename T>
T& Array<T>::operator[] (int i) const
{
	if (i < 0 || (unsigned int)i >= size())
		throw Array<T>::OutOfBoundException();
	return this->_array[i];
}

template<typename T>
Array<T>& Array<T>::operator= (const Array<T>& array)
{
	delete _array;
	_size = array.size();
	_array = NULL;
	if (_size)
		_array = new T [_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = array[i];
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif /* ARRAY_HPP */
