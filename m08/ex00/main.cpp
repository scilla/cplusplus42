#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(3);
	v.push_back(66);
	int diff = easyfind(v, 1) - v.begin();
	std::cout << diff << std::endl;


	{
		std::cout << "ARRAY" << std::endl;

		std::array<int, 4>	a = {1, 2, 3, 4};
		std::array<int, 4>::iterator	it;

		try
		{
			it = easyfind(a, 3);
			std::cout << *it << std::endl;
			std::replace(a.begin(), a.end(), 3, 5);
			it = easyfind(a, 3);
			std::cout << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	
	{
		std::cout << "VECTOR" << std::endl;

		std::vector<int>	a(5, 5);
		std::vector<int>::iterator	it;

		try
		{
			it = easyfind(a, 3);
			std::cout << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "DEQUE" << std::endl;

		std::deque<int>	a(5, 5);
		std::deque<int>::iterator	it;

		try
		{
			it = easyfind(a, 5);
			std::cout << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}