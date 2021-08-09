#include "span.hpp"

int	main()
{
	{
		Span	s(10);

		try
		{
			std::cout << s.shortestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << s.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			s.addNumber(1);
			s.addNumber(3);
			s.addNumber(6);
			s.addNumber(8);
			s.addNumber(20);
			s.addNumber(-6);
			s.addNumber(12);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << s.shortestSpan() << std::endl;
			std::cout << s.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		Span	x(s);

		try
		{
			x.addNumber(30);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << x.shortestSpan() << std::endl;
			std::cout << x.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		x = s;

		try
		{
			std::cout << x.shortestSpan() << std::endl;
			std::cout << x.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	// {
	// 	Span	s(10001);

	// 	try
	// 	{
	// 		s.addRange(-5000, 5000);
	// 	}
	// 	catch (const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}

	// 	try
	// 	{
	// 		std::cout << s.shortestSpan() << std::endl;
	// 		std::cout << s.longestSpan() << std::endl;
	// 	}
	// 	catch (const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }

	// {
	// 	Span	s(10001);

	// 	try
	// 	{
	// 		s.addRandom(10000);
	// 	}
	// 	catch (const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}

	// 	try
	// 	{
	// 		std::cout << s.shortestSpan() << std::endl;
	// 		std::cout << s.longestSpan() << std::endl;
	// 	}
	// 	catch (const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
}