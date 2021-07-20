#include <iostream>
#include <string>
#include <fstream>

bool file_exist(const char *fileName)
{
    std::ifstream testFile(fileName);
    return testFile.good();
}

int	main(int argc, char **argv) {
	std::string		fileBaseName;
	std::string		oldSubs;
	std::string		newSubs;
	std::ifstream	inFile;
	std::ofstream	outFile;

	if (argc != 4)
	{
		std::cout << "wrong number of args" << std::endl;
		return 1;
	}
	oldSubs.assign(argv[2]);
	newSubs.assign(argv[3]);
	if (oldSubs.empty() || oldSubs.empty()) {
		std::cout << "substrings can't be empy" << std::endl;
		return 1;
	}
	inFile.open(fileBaseName);
	if (!inFile.good()) {
		std::cout << "Error opening file " << fileBaseName << std::endl;
		return 1;
	}
	fileBaseName.assign(argv[1]);
	/*
	if (file_exist((fileBaseName + ".replace").c_str()))
	{
		std::cout << fileBaseName + ".replace" << " already exists, quitting" << std::endl;
		return 1;
	}
	*/
	outFile.open(fileBaseName + ".replace");
	outFile << "ciao\n";
	return 0;
}