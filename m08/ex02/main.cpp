#include "mutantstack.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <deque>

int main(void)
{
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	std::stack<int> mystack;          // deque with 3 elements
	mystack.push(11);
	std::vector<int> myvector (2,200);        // vector with 2 elements
	
	MutantStack<int> s(mystack);
	MutantStack<int> t(myvector);
	MutantStack<int> u(mydeque);

	s.push(10);
	s.push(20);

	std::cout << s.top() << std::endl;
	return 0;
}
