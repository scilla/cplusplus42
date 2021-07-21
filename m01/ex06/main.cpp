#include "Karen.hpp"
#include <string>

int find_ind(std::string level, std::string levelArr[]) {
	for (unsigned int i = 0; i < levelArr->length(); i++) {
		if (levelArr[i] == level)
			return i;
	}
	return -1;
}

int	main(int argc, char **argv) {
	Karen	karen;
	std::string		level;
	std::string		levelArr[] = {"DEBUG", "INFO", "WARNING", "ERROR", "42"};

	if (argc != 2)
	{
		std::cout << "Wrong number of args" << std::endl;
		return 1;
	}
	level.assign(argv[1]);
	switch (find_ind(level, levelArr))
	{
	case 0:
		karen.complain("DEBUG");
	case 1:
		karen.complain("INFO");
	case 2:
		karen.complain("WARNING");
	case 3:
		karen.complain("ERROR");
		break;
	default:
		karen.complain("42");
		break;
	}
	return 0;
}