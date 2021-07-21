#include "Karen.hpp"
#include <string>

int	main(int argc, char **argv) {
	Karen	karen;
	std::string		level;

	if (argc != 2)
	{
		std::cout << "Wrong number of args" << std::endl;
		return 1;
	}
	level.assign(argv[1]);
	karen.setDebugLevel(level);
	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");
	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");
	return 0;
}