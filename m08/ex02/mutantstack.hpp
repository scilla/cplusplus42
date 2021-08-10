#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <vector>
#include <deque>

template<typename T, typename C = std::deque<T> >
class MutantStack: public std::stack<T, C>
{
public:
	MutantStack(std::vector<T>& orig);
	MutantStack(std::deque<T>& orig);
	MutantStack(std::stack<T>& orig);
};

template<typename T, typename C>
MutantStack<T, C>::MutantStack(std::vector<T>& orig): std::stack<T, C>(orig)
{
}

template<typename T, typename C>
MutantStack<T, C>::MutantStack(std::deque<T>& orig): std::stack<T, C>(orig)
{
}

template<typename T, typename C>
MutantStack<T, C>::MutantStack(std::stack<T>& orig): std::stack<T, C>(orig)
{
}

#endif /* MUTANTSTACK_HPP */
