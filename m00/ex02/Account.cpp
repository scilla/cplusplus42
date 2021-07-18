#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account() {
	this->_nbAccounts--;
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

Account::Account(int amount) {
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_amount = amount;
	this->_totalAmount += amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

void	Account::_displayTimestamp() {
	size_t		res;
	char		str[18];
	time_t		rawtime;
	struct tm	*timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	res = strftime(str, 19, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << str;
}

int	Account::getNbAccounts( void ) { return t::_nbAccounts; }
int	Account::getTotalAmount( void ) { return t::_totalAmount; }
int	Account::getNbDeposits( void ) { return t::_totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return t::_totalNbWithdrawals; }

void Account::displayAccountsInfos() {
	t::_displayTimestamp();
	std::cout << "accounts:" << t::getNbAccounts() << ";";
	std::cout << "total:" << t::getTotalAmount() << ";";
	std::cout << "deposits:" << t::getNbDeposits() << ";";
	std::cout << "withdrawals:" << t::getNbWithdrawals() << std::endl;
}

void Account::displayStatus() const {
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	t::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal <= this->_amount) {
		std::cout << withdrawal << ";";
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	} else {
		std::cout << "refused" << std::endl;
		return false;
	}
}