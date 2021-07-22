#include "Zombie.hpp"
#include "ZombieHorde.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(void) {
	Zombie	*horde;
	std::string	name = "Smurf";

	horde = zombieHorde(10, name);
	for (size_t i = 0; i < 10; i++)
		horde[i].announce();
	delete [] horde;
	return 0;
}