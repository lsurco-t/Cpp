#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(){
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);  
	std::cout << "[" << std::put_time(localTime, "%Y%m%d_%H%M%S") << "]";
}

Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0) {

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout  << "index:"  << _accountIndex 
			   << ";amount:" << _amount
			   << ";created" << std::endl;
}

Account::~Account(){

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _totalAmount
			  << ";closed" << std::endl;
}

int Account::getNbAccounts() {return _nbAccounts;}
int	Account::getTotalAmount() {return _totalAmount;}
int	Account::getNbDeposits()  {return _totalNbDeposits;}
int	Account::getNbWithdrawals(){return _totalNbWithdrawals;}

void Account::displayAccountsInfos(){

	_displayTimestamp();

	std::cout << "accounts:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ){

	_amount += deposit;	
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

}

bool	Account::makeWithdrawal( int withdrawal ){

	if (withdrawal > _amount)
		return (false);

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -+ withdrawal;
	_totalNbWithdrawals++;

	return (true);
}

int		Account::checkAmount() const{
	
}

void	Account::displayStatus() const{

}