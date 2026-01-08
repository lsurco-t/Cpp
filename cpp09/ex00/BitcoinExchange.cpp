#include "BitcoinExchange.hpp"

enum INVALID_FILE {
	IS_EMPTY,
	IS_DIR,
	NOT_EXIST,
	WRONG_PERMS
};

void	BitcoinExchange::loadDatabase(const std::string& filename){
	std::string line;
	std::ifstream input(filename);
	if (!input){
		std::cout << "Error: could not open database file\n";
		return;
	}
	std::getline(input, line);
	while(std::getline(input, line)){
		
	}
	
}

void 	BitcoinExchange::processLine(const std::string& line){

}

double	BitcoinExchange::getExchangeRate(const std::string& date) const {

}

bool BitcoinExchange::isValidFile(const std::string& filename){
	std::error_code ec;
	auto status = std::filesystem::status(filename, ec);
	auto perms = status.permissions();

	if (!std::filesystem::exists(filename, ec)){
		return returnErrMessage(NOT_EXIST, filename);
	}
	else if ((perms & std::filesystem::perms::owner_read) == std::filesystem::perms::none &&
				(perms & std::filesystem::perms::owner_write) == std::filesystem::perms::none){
		return returnErrMessage(WRONG_PERMS, filename);
	}
	else if (std::filesystem::is_directory(filename, ec)){
		return returnErrMessage(IS_DIR, filename);
	}
	else if (std::filesystem::is_empty(filename, ec)){
		return returnErrMessage(IS_EMPTY, filename);
	}	
	return true;
}

bool BitcoinExchange::returnErrMessage(unsigned int reason, const std::string& file){
	std::string reasonStr;
	switch(reason){
		case IS_EMPTY:
			reasonStr = " is empty\n";
			break;
		case IS_DIR:
			reasonStr = " is a directory\n";
			break;
		case NOT_EXIST:
			reasonStr = " does not exist\n";
			break;
		case WRONG_PERMS:
			reasonStr = " has not enough perms to write or read\n";
	}
	std::cout << "Error: File " << file << reasonStr;
	return false;
}

