#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &cat) {
	*this = cat;
}

WrongCat &WrongCat::operator=(const WrongCat &cat) {
	type = cat.type;
	return *this;
}

WrongCat::~WrongCat() {

}

void	WrongCat::makeSound() const {
	std::cout << "<3 <3 <3 I lowww my owner and just beacuse he gives me food <3 <3 <3" << std::endl;
}
