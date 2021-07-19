#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void) {
	Zombie	*horde;
	std::string	name = "Smurf";

	horde = zombieHorde(10, name);
	delete [] horde;
	return 0;
}