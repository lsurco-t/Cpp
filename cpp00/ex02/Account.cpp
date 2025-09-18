#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(){

	std::time_t now = std::time(0);
	std::tm* localTime = std::localtime(&now);  

	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
	std::cout << buffer;
}

Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0) {

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout  << " index:"  << _accountIndex 
			   << ";amount:" << _amount
			   << ";created" << std::endl;
}

Account::~Account(){

	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

int Account::getNbAccounts() {return _nbAccounts;}
int	Account::getTotalAmount() {return _totalAmount;}
int	Account::getNbDeposits()  {return _totalNbDeposits;}
int	Account::getNbWithdrawals(){return _totalNbWithdrawals;}

void Account::displayAccountsInfos(){

	_displayTimestamp();

	std::cout << " accounts:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ){

	_displayTimestamp();

	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << _amount;

	_amount += deposit;	
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){

	if (withdrawal > _amount){

		_displayTimestamp();
		std::cout << " index:" << _accountIndex
				  << ";p_amount:" << _amount
				  << ";withdrawal:refused" << std::endl;
		return (false);

	}

	_displayTimestamp();

	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << _amount;

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount() const {return _amount;}

void	Account::displayStatus() const {

	_displayTimestamp();

	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}