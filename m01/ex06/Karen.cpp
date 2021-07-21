#include "Karen.hpp"

Karen::Karen(/* args */)
{
	this->kFunctArray["DEBUG"] = &Karen::debug;
	this->kFunctArray["INFO"] = &Karen::info;
	this->kFunctArray["WARNING"] = &Karen::warning;
	this->kFunctArray["ERROR"] = &Karen::error;
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

void Karen::complain(std::string level) {
	if (this->kFunctArray.find(level) != this->kFunctArray.end())
		(this->*kFunctArray[level])();
	else
	{
		std::cout << "[undefined] Can. You. Speak. English?" << std::endl;
	}
}