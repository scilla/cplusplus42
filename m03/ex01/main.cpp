#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap vincenzo("Vincenzo");
	ClapTrap francesca("Francesca");
	ClapTrap edoardo("Edoardo");

	edoardo.beRepaired(33);
	vincenzo.attack(edoardo.getName());
	edoardo.takeDamage(vincenzo.getAttackDamage());
	edoardo.attack(vincenzo.getName());
	vincenzo.takeDamage(edoardo.getAttackDamage());
	vincenzo.guardGate();
	vincenzo.guardGate();
	edoardo.beRepaired(60);
	vincenzo.takeDamage(999);
	return 0;
}
