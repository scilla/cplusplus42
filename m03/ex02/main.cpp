#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ScavTrap vincenzo("Vincenzo");
	FragTrap francesca("Francesca");
	ClapTrap edoardo("Edoardo");

	edoardo.beRepaired(22);
	vincenzo.attack(edoardo.getName());
	edoardo.takeDamage(vincenzo.getAttackDamage());
	edoardo.attack(vincenzo.getName());
	vincenzo.takeDamage(edoardo.getAttackDamage());
	francesca.attack(edoardo.getName());
	edoardo.takeDamage(francesca.getAttackDamage());
	vincenzo.guardGate();
	vincenzo.guardGate();
	edoardo.beRepaired(60);
	vincenzo.takeDamage(999);
	francesca.highFivesGuys();
	return 0;
}
