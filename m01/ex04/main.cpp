#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

bool file_exist(const char *fileName)
{
    std::ifstream testFile(fileName);
    return testFile.good();
}

int	main(int argc, char **argv) {
	std::string		fileBaseName;
	std::string		oldSubs;
	std::string		newSubs;
	std::string		inStr;
	std::ifstream	inFile;
	std::ofstream	outFile;
    std::ostringstream ss;

	if (argc != 4)
	{
		std::cout << "Wrong number of args" << std::endl;
		return 1;
	}
	oldSubs.assign(argv[2]);
	newSubs.assign(argv[3]);
	if (oldSubs.empty() || oldSubs.empty()) {
		std::cout << "Substrings can't be empy" << std::endl;
		return 1;
	}
	fileBaseName.assign(argv[1]);
	inFile.open(fileBaseName);
	if (!inFile.good()) {
		std::cout << "Error opening file " << fileBaseName << std::endl;
		return 1;
	}
	if (file_exist((fileBaseName + ".replace").c_str()))
	{
		std::cout << fileBaseName + ".replace" << " already exists, quitting" << std::endl;
		return 1;
	}
	outFile.open(fileBaseName + ".replace");
	if (!outFile.good()) {
		std::cout << "Error opening file " << fileBaseName + ".replace" << std::endl;
		return 1;
	}
	ss << inFile.rdbuf();
	inFile.close();
	inStr = ss.str();
	for (size_t i = 0; i < inStr.length(); i++)
	{
		i = inStr.find(oldSubs, i);
		if (i == std::string::npos)
			break ;
		inStr.erase(i, oldSubs.length());
		inStr.insert(i, newSubs);
		i += newSubs.length();
	}
	outFile << inStr;
	outFile.close();
	return 0;
}