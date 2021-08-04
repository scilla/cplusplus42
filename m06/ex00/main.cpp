#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <cmath>

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
		if (!i && (str[i] == '-' || str[i] == '+'))
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
	double intpart;
	//unsigned int precision = 30;
	//char* end;

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
		char_res = static_cast<char>(int_res);
		float_res = static_cast<float>(int_res);
		double_res = static_cast<double>(int_res);
	}
	else if (isAFloat(str))
	{
		std::cout << "is a float " << std::endl;
		float_res = std::atof(str.c_str());
		int_res = static_cast<int>(float_res);
		char_res = static_cast<char>(float_res);
		double_res = static_cast<double>(float_res);
	}
	else if (isADouble(str))
	{
		std::cout << "is a double " << std::endl;
		double_res = std::atof(str.c_str());
		int_res = static_cast<int>(double_res);
		char_res = static_cast<char>(double_res);
		float_res = static_cast<float>(double_res);
	}
	else
		std::cout << "else" << std::endl;

	if ()
	std::cout << "char: " << char_res << std::endl;
	std::cout << "int: " << int_res << std::endl;
	if (!modf(float_res, &intpart))
		std::cout << "float: " << std::setprecision(7) << float_res << ".0" << 'f' << std::endl;
	else
		std::cout << "float: " << std::setprecision(7) << float_res << 'f' << std::endl;
	if (!modf(double_res, &intpart))
		std::cout << "double: " << std::setprecision(16) << double_res << ".0" << std::endl;
	else
		std::cout << "double: " << std::setprecision(16) << double_res << std::endl;

	return 0;
}
