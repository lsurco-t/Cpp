#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){}

Account::~Account(){}

int  Account::getNbAccounts() {return _nbAccounts;}
int	Account::getTotalAmount() {return _totalAmount;}
int	Account::getNbDeposits()  {return _totalNbDeposits;}
int	Account::getNbWithdrawals(){return _totalNbWithdrawals;}

void Account::displayAccountsInfos(){

	_displayTimestamp();

	std::cout << "Number Accounts" << Account::getNbAccounts()
			  << "total amount" << Account::getTotalAmount()
			  << "total deposits" << Account::getNbDeposits()
			  << "total withdrawals" << Account::getNbWithdrawals << std::endl;
}