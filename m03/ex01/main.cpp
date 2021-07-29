#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap vincenzo("Vincenzo");
	ClapTrap francesca("Francesca");
	ClapTrap edoardo("Edoardo");

	edoardo.beRepaired(100);
	for (int i = 0; i < 11; i++) {
		vincenzo.attack(edoardo.getName());
		edoardo.takeDamage(vincenzo.getAttackDamage());
	}
	vincenzo.beRepaired(10);
	vincenzo.takeDamage(999);
	return 0;
}