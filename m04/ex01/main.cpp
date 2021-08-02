#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Dog adamdog;
	Cat adamcat;
	Animal* animals[10];

	adamdog.setIdea(0, "Play");
	adamcat.setIdea(0, "Sleep");
	for (int i = 0; i < 2; i++){
		if (i % 2)
			animals[i] = new Cat(adamcat);
		else
			animals[i] = new Dog(adamdog);
	}
	std::cout << animals[0]->getIdea(0) << std::endl;
	std::cout << animals[1]->getIdea(0) << std::endl;
	animals[0]->setIdea(0, "Explore");
	animals[1]->setIdea(0, "Eat");
	std::cout << animals[0]->getIdea(0) << std::endl;
	std::cout << animals[1]->getIdea(0) << std::endl;
	std::cout << adamdog.getIdea(0) << std::endl;
	std::cout << adamcat.getIdea(0) << std::endl;
	for (int i = 0; i < 2; i++){
		delete animals[i];
	}
	return 0;
}