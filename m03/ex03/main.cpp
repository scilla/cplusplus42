#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	ClapTrap edoardo("Edoardo");
	ScavTrap vincenzo("Vincenzo");
	FragTrap francesca("Francesca");
	DiamondTrap ciro("Ciro");

	edoardo.beRepaired(22);
	vincenzo.attack(edoardo.getName());
	edoardo.takeDamage(vincenzo.get_attackDamage());
	edoardo.attack(vincenzo.getName());
	vincenzo.takeDamage(edoardo.get_attackDamage());
	francesca.attack(edoardo.getName());
	edoardo.takeDamage(francesca.get_attackDamage());
	vincenzo.guardGate();
	vincenzo.guardGate();
	edoardo.beRepaired(60);
	vincenzo.takeDamage(999);
	francesca.highFivesGuys();
	ciro.whoAmI();
	
	ciro.attack(francesca.getName());
	francesca.takeDamage(ciro.get_attackDamage());
	francesca.attack(ciro.getName());
	ciro.takeDamage(francesca.get_attackDamage());
	//ciro.guardGate();
	// ciro.highFivesGuys();
	return 0;
}
