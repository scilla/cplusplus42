#include "Karen.hpp"

Karen::Karen()
{
	this->kFunctArray[0] = &Karen::debug;
	this->kFunctArray[1] = &Karen::info;
	this->kFunctArray[2] = &Karen::warning;
	this->kFunctArray[3] = &Karen::error;
	this->kFunctArray[4] = &Karen::undefined;
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
}

Karen::~Karen()
{
}

void Karen::debug( void ) {
	std::cout << "[DEBUG] Oh dear teacher I wish everyone would have kids like mine, your work would be even easier" << std::endl;
}

void Karen::info( void ) {
	std::cout << "[INFO] Here's a photo when he was 4years, 8month and 2weeks old, he almost managed to make a cup with play dough, he's so smart" << std::endl;
}

void Karen::warning( void ) {
	std::cout << "[WARNING] I think my kid deservers better grades, he's always in his room studying!!! What? Yes the door is always locked, why should it matter? He SWEARS he studied" << std::endl;
}

void Karen::error( void ) {
	std::cout << "[ERROR] YoUr BunCH OF iPOcRTTe iLLetIraTE yoU cLeN YR mOuTH wHEn TaLkIn BOuT mY KidS IMmA GoNnA KiLL yOu!!!!" << std::endl;
}

void Karen::undefined( void ) {
	std::cout << "[undefined] Can. You. Speak. English?" << std::endl;
}

void Karen::complain(std::string level) {
	int	ind = 4;
	for (int k = 0; k < 4; k++) {
		if (this->levels[k] == level) {
			ind = k;
			break;
		}
	}
	(this->*kFunctArray[ind])();
}