#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <vector>
#include <deque>

//template<typename T, typename C = std::deque<T> >
template<class T>
class MutantStack: public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack(): std::stack<T>() {};
	~MutantStack() {};
	template<typename C>
	MutantStack(const C& orig);
	MutantStack(const MutantStack& mstack): std::stack<T>(mstack) {};
	MutantStack<T>& operator= (const MutantStack<T>& mstack) {
		std::stack<T>::operator=(mstack);
		return *this;
	}
	/*
	MutantStack(std::vector<T>& orig);
	MutantStack(std::deque<T>& orig);
	MutantStack(std::stack<T>& orig);
	*/
	/*
	class iterator
	{
	private:
		int	_ind;
		std::vector<T*> _ptrs;
	public:
		void update();
	};
	*/
	iterator begin()
	{
		return std::stack<T>::c.begin();
	}

	iterator end()
	{
		return std::stack<T>::c.end();
	}
};


template<class T>
template<class C>
MutantStack<T>::MutantStack(const C& orig): std::stack<T, C>(orig)
{
}

/*
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
*/
/*
template<typename T, typename C>
void MutantStack<T, C>::iterator::update() {
	_ptrs.clear();
	std::stack<T> tmp;
	while (!this->empty())
	{
		tmp.push_back(this->pop_back());
	}
	while (!tmp.empty())
	{
		this->push_back(tmp.pop_back());
		_ptrs.push(this->top());
	}
}
*/
#endif /* MUTANTSTACK_HPP */
