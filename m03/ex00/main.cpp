#include "ClapTrap.hpp"

int main() {
	ClapTrap vincenzo("Vincenzo");
	ClapTrap francesca("Francesca");
	ClapTrap edoardo("Edoardo");

	for (int i = 0; i < 11; i++) {
		vincenzo.attack(edoardo.getName());
		edoardo.takeDamage(vincenzo.getAttackDamage());
	}
	vincenzo.beRepaired(10);
	vincenzo.takeDamage(999);
	return 0;
}