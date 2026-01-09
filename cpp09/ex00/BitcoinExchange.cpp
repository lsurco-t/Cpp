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
		size_t comma = line.find(',');
		if (comma == std::string::npos){
			std::cout << "Error: bad format found\n";
			return;
		}
		std::string date = line.substr(0, comma);
		std::string value = line.substr(comma + 1);
		try {
			size_t pos;
			double numericValue = stod(value, &pos);
			if (pos != value.length()){
				std::cout << "Error: invalid characters found in value\n";
				return;
			}
			if (numericValue < 0){
				std::cout << "Error: negative value found\n";
				return ;
			}
		} catch (std::exception &except) {
			throw except.what();
		}
	}
}

void 	BitcoinExchange::processLine(const std::string& line){
	// std::string line;
	// std::ifstream input(filename);
	// std::getline(input, line);
	// while(std::getline(input, line)){
	// 	std::istringstream ss(line);
	// 	std::string pipe;
	// 	std::string date;
	// 	std::string value;

	// 	ss >> date >> pipe >> value;
	// 	double	nbrValue = stod(value);

	// 	if (!isValidDate(date)){
	// 		std::cout << "Error: wrong date format\n";
	// 		return;
	// 	}
	// 	if (pipe != "|"){
	// 		std::cout << "Error: incorrect separator used\n";
	// 		return ;
	// 	}
	// 	if (nbrValue <= 0){
	// 		std::cout << "Error: value must be positive\n";
	// 		return ;
	// 	} else if (nbrValue >= 1000){
	// 		std::cout << "Error: value must be less than 1000\n";
	// 	}
	// }	
}

double	BitcoinExchange::getExchangeRate(const std::string& date) const {

}

bool	BitcoinExchange::isValidDate(const std::string& date, const std::string& separator){	
	
		if (date.length() != 10 || date[4] != '-' || date[7] != '-'){
			std::cout << "Error: wrong date format\n";
			return;
		}
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

