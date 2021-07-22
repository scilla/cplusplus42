#include "Karen.hpp"

Karen::Karen()
{
	this->kFunctArray[0] = &Karen::debug;
	this->kFunctArray[1] = &Karen::info;
	this->kFunctArray[2] = &Karen::warning;
	this->kFunctArray[3] = &Karen::error;
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
	this->debugLevel = WARNING;
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

/* this is stupid */
void Karen::setDebugLevel(std::string level) {
	int dbl = -1;
	for (int k = 0; k < 4; k++) {
		if (this->levels[k] == level) {
			dbl = k;
			break;
		}
	}
	switch (dbl)
	{
	case 0:
		this->debugLevel = DEBUG;
		break;
	case 1:
		this->debugLevel = INFO;
		break;
	case 2:
		this->debugLevel = WARNING;
		break;
	case 3:
		this->debugLevel = ERROR;
		break;
	default:
		this->debugLevel = WARNING;
		std::cout << "[WARNING] " << level << " not a debug level, falling back to WARNING" << std::endl;
		break;
	}
}

void Karen::complain(std::string level) {
	for (int k = this->debugLevel; k < 4; k++) {
		if (this->levels[k] == level) {
			(this->*kFunctArray[k])();
			return;
		}
	}
}