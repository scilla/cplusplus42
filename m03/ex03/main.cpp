#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	// ClapTrap edoardo("Roberto");
	// ScavTrap vincenzo("Vincenzo");
	ScavTrap francesca("Francesca");
	DiamondTrap ciro("Ciro");
/*
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
	ciro.whoAmI();
	*/
	ciro.attack(francesca.getName());
	francesca.takeDamage(ciro.getAttackDamage());
	francesca.attack(ciro.getName());
	ciro.takeDamage(francesca.getAttackDamage());
	ciro.guardGate();
	// ciro.highFivesGuys();
	return 0;
}
