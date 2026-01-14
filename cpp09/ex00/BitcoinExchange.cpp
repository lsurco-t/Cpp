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
		return;
	}
	std::getline(input, line); // Skip header
	while(std::getline(input, line)){
		if (line.empty()){
			continue; // Skip blank lines
		}
		size_t comma = line.find(',');
		if (comma == std::string::npos || comma == 0 || comma == line.length() - 1){
			continue; // Skip malformed lines
		}
		std::string date = line.substr(0, comma);
		std::string value = line.substr(comma + 1);
		try {
			double numericValue = std::stod(value);
			_database[date] = numericValue;
		} catch (const std::exception&) {
			continue; // Skip unparseable values
		}
	}
}

void	BitcoinExchange::processInputFile(const std::string& filename){
	std::string	  line;
	std::ifstream input(filename);
	std::getline(input, line);
	while(std::getline(input, line)){
		if (line.empty()){
			continue;
		}
		processLine(line);
	}
}

void 	BitcoinExchange::processLine(const std::string& line){
		std::string date;
		std::string pipe;
		std::string value;
		std::istringstream ss(line);
		ss >> date >> pipe >> value;
		if (ss.fail() || date.empty() || pipe.empty() || value.empty()){
			std::cout << "Error: bad input => " << line << '\n';
			return;
		}
		try {
			if (!isValidDate(date)){
				std::cout << "Error: bad input => " << line << '\n';
				return;
			}
			if (pipe != "|"){
				std::cout << "Error: bad input => " << line << '\n';
				return;
			}
			double	nbrValue = stod(value);
			if (nbrValue <= 0){
				std::cout << "Error: not a positive number.\n";
				return;
			} else if (nbrValue > 1000){
				std::cout << "Error: too large a number.\n";
				return;
			}
			double rate = getExchangeRate(date);
			if (rate < 0){
				std::cout << "Error: no data available for this date.\n";
				return;
			}
			double result = nbrValue * rate;
			std::cout << date << " => " << nbrValue << " = " << result << std::endl;
		} catch (std::exception &e){
			std::cout << "Error: too large a number.\n";
			return;
		}
}

double	BitcoinExchange::getExchangeRate(const std::string& date) const {
	auto it = _database.upper_bound(date);
	if (it == _database.begin()){
		return -1;
	}
	--it;
	return it->second;
}

bool	BitcoinExchange::isValidDate(const std::string& date){
	// Check correct format
	if (date.length() != 10 || date[4] != '-' || date[7] != '-'){
		return false;
	}
	try {
		// Convert to numbers
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		// Check correct range values
		if (year <= 0 || (month < 1 || month > 12)){
			return false;
		}

		// Check days values
		int maxDay = months[month - 1];
		if (isLeapYear(year) && month == 2){
			maxDay = 29;
		}
		if (day < 1 || day > maxDay){
			return false;
		}
	} catch (std::exception &e) {
		return false;
	}
	return true;
}

bool	BitcoinExchange::isLeapYear(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidFile(const std::string& filename){
	std::error_code ec;
	auto status = std::filesystem::status(filename, ec);
	auto perms = status.permissions();

	if (!std::filesystem::exists(filename, ec)){
		return returnErrMessage(NOT_EXIST, filename);
	}
	else if ((perms & std::filesystem::perms::owner_read) == std::filesystem::perms::none){
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

