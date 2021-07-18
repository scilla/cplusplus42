#include <iostream>

int main(int argc, char **argv) {
	std::string str;

	if (argc > 1) {
		for (int i = 1; i < argc; i++)
			str.append(argv[i]);
	}
	else
		str.assign("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	for (unsigned int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	std::cout << str << std::endl;
	return 0;
}