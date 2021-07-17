#include <iostream>

int main(int argc, char **argv) {
	std::string str;

	if (argc > 1) {
		for (int i = 1; i < argc; i++)
			str.append(argv[i]);
	}
	else
		str.append("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	std::transform(str.begin(), str.end(), str.begin(), toupper);
	std::cout << str << std::endl;
	return 0;
}