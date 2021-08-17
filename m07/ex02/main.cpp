#include "Array.hpp"
#include "Test.hpp"
#define MAX_VAL 750

int	main()
{
	{
		std::cout << std::endl << " ##### INT ##### " << std::endl << std::endl;

		Array<int> a(5);

		a[0] = 0;
		a[1] = 1;
		a[2] = 2;
		a[3] = 3;
		a[4] = 4;

		Array<int> b(a);

		Array<int> c;

		std::cout << a.size() << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << c.size() << std::endl;

		try
		{
			a[5] = 5;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			b[5] = 5;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			c[1] = 1;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		c = a;

		std::cout << c.size() << std::endl;

		try
		{
			c[1] = 1;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << a[1] << std::endl;
		std::cout << b[1] << std::endl;
		std::cout << c[1] << std::endl;

		b[1] = 2;
		c[1] = 3;

		std::cout << a[1] << std::endl;
		std::cout << b[1] << std::endl;
		std::cout << c[1] << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << std::endl << " ##### FLOAT ##### " << std::endl << std::endl;

		Array<float> a(5);

		a[0] = 0.5;
		a[1] = 1.5;
		a[2] = 2.5;
		a[3] = 3.5;
		a[4] = 4.5;

		Array<float> b(a);

		Array<float> c;

		std::cout << a.size() << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << c.size() << std::endl;

		try
		{
			a[5] = 5.5;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			b[5] = 5.5;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			c[1] = 1.5;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		c = a;

		std::cout << c.size() << std::endl;

		try
		{
			c[1] = 1.5;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << a[1] << std::endl;
		std::cout << b[1] << std::endl;
		std::cout << c[1] << std::endl;

		b[1] = 2.5;
		c[1] = 3.5;

		std::cout << a[1] << std::endl;
		std::cout << b[1] << std::endl;
		std::cout << c[1] << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << std::endl << " ##### STRING ##### " << std::endl << std::endl;

		Array<std::string> a(5);

		a[0] = "zero";
		a[1] = "uno";
		a[2] = "due";
		a[3] = "tre";
		a[4] = "quatto";

		Array<std::string> b(a);

		Array<std::string> c;

		std::cout << a.size() << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << c.size() << std::endl;

		try
		{
			a[5] = "cinque";
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			b[5] = "cinque";
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			c[1] = "uno";
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		c = a;

		std::cout << c.size() << std::endl;

		try
		{
			c[1] = "uno";
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << a[1] << std::endl;
		std::cout << b[1] << std::endl;
		std::cout << c[1] << std::endl;

		b[1] = "due";
		c[1] = "tre";

		std::cout << a[1] << std::endl;
		std::cout << b[1] << std::endl;
		std::cout << c[1] << std::endl;
	}

	{
		std::cout << std::endl << " ##### CLASS ##### " << std::endl << std::endl;

		Array<Test> a(5);

		a[0] = 0;
		a[1] = 1;
		a[2] = 2;
		a[3] = 3;
		a[4] = 4;

		Array<Test> b(a);

		Array<Test> c;

		std::cout << a.size() << std::endl;
		std::cout << b.size() << std::endl;
		std::cout << c.size() << std::endl;

		try
		{
			a[5] = 5;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			b[5] = 5;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			c[1] = 1;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		c = a;

		std::cout << c.size() << std::endl;

		try
		{
			c[1] = 1;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << a[1] << std::endl;
		std::cout << b[1] << std::endl;
		std::cout << c[1] << std::endl;

		b[1] = 2;
		c[1] = 3;

		std::cout << a[1] << std::endl;
		std::cout << b[1] << std::endl;
		std::cout << c[1] << std::endl;
	}
	
	std::cout << std::endl << " ##### default ##### " << std::endl << std::endl;

	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	return (0);
}