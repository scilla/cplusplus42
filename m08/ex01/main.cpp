#include "span.hpp"

int	main()
{
	{
		Span	s(7);

		try
		{
			std::cout << "Shortest: " << s.shortestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << "Longest: " << s.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			s.addNumber(1);
			s.addNumber(10);
			s.addNumber(6);
			s.addNumber(8);
			s.addNumber(1);
			s.addNumber(-6);
			s.addNumber(12);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << "Shortest: " << s.shortestSpan() << std::endl;
			std::cout << "Longest: " << s.longestSpan() << std::endl;
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
			std::cout << "Shortest: " << x.shortestSpan() << std::endl;
			std::cout << "Longest: " << x.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		x = s;

		try
		{
			std::cout << "Shortest: " << x.shortestSpan() << std::endl;
			std::cout << "Longest: " << x.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		Span	s(10001);

		try
		{
			s.addRange(-5000, 5000);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << "Shortest: " << s.shortestSpan() << std::endl;
			std::cout << "Longest: " << s.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		Span	s(10001);

		try
		{
			s.addRandom(10000);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << "Shortest: " << s.shortestSpan() << std::endl;
			std::cout << "Longest: " << s.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}