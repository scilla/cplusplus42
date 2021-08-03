#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>

bool isAChar(std::string str)
{
	if (str.length() != 1)
		return false;
	if (str[0] >= '0' && str[0] <= '9')
		return false;
	return true;
}

bool isAInt(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!i && str[i] == '-')
			continue;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool isAFloat(std::string str)
{
	char* end;
	double f = std::strtod(str.c_str(), &end);
	if (end == str.c_str() + str.size() - 1 && *end == 'f')
		return true;
	(void)f;
	return false;
}

bool isADouble(std::string str)
{
	char* end;
	double f = std::strtod(str.c_str(), &end);
	if (end == str.c_str() + str.size())
		return true;
	(void)f;
	return false;
}

int main(int argc, char const *argv[])
{
	char	char_res = 0;
	int		int_res = 0;
	float	float_res = 0;
	double	double_res = 0;
	unsigned int precision = 30;
	
	char* end;
	if (argc != 2 || std::string(argv[1]).length() == 0){
		std::cout << "wrong args" << std::endl;
		return 0;
	}
	std::string str(argv[1]);
	if (isAChar(str))
	{
		std::cout << "is a char" << std::endl;
		char_res = str[0];
		int_res = static_cast<int>(char_res);
		float_res = static_cast<float>(char_res);
		double_res = static_cast<double>(char_res);
	}
	else if (isAInt(str))
	{
		std::cout << "is a int" << std::endl;
		int_res = atoi(str.c_str());
		char_res = static_cast<int>(int_res);
	}
	else if (isAFloat(str))
	{
		std::cout << "is a float " << "f" << std::endl;
	}
	else if (isADouble(str))
	{
		std::cout << "is a double " << std::strtod(str.c_str(), &end) << std::endl;
	}
	else
		std::cout << "else" << std::endl;

	std::cout << "char: " << char_res << std::endl;
	std::cout << "int: " << int_res << std::endl;
	std::cout << "float: " << float_res << std::endl;
	std::cout << "double: " << double_res << std::endl;

	return 0;
}
