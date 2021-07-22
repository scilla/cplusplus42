#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main(void) {
	Zombie	*zombie;

	zombie = newZombie("Orco Farlocco");
	zombie->announce();
	randomChump("Giovanni Muciaccia");
	delete zombie;
	return 0;
}