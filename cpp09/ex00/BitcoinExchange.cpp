#include "BitcoinExchange.hpp"

enum INVALID_FILE {
	IS_EMPTY,
	IS_DIR,
	NOT_EXIST,
	WRONG_EXT,

};

bool BitcoinExchange::isValidFile(std::string& file){
	std::error_code ec;
	if (!std::filesystem::exists(file, ec)){
		return returnMessage(NOT_EXIST, file);
	}
	else if (std::filesystem::path(file).extension() != ".txt"){
		return returnMessage(WRONG_EXT, file);
	}
	else if (std::filesystem::is_directory(file, ec)){
		return returnMessage(IS_DIR, file);
	}
	else if (std::filesystem::is_empty(file, ec)){
		return returnMessage(IS_EMPTY, file);
	}	
	return true;
}

unsigned int BitcoinExchange::matchPrice(std::string_view input, std::string_view database){

}

void BitcoinExchange::displayOutput(std::string_view input, unsigned int price){

}

bool returnMessage(unsigned int reason, std::string& file){
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
		case WRONG_EXT:
			reasonStr = " has wrong extension\n";
			break;
	}
	std::cout << "File " << file << reasonStr;
	return false;
}

