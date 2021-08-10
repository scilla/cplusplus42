#include "mutantstack.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <deque>

int main(void) {

	std::deque<int> mydeque (3,100);          // deque with 3 elements
	std::vector<int> myvector (2,200);        // vector with 2 elements
	
	MutantStack<int, std::vector<int> > s(myvector);

	s.push(10);
	s.push(20);

	std::cout << s.top() << std::endl;
	return 0;
}