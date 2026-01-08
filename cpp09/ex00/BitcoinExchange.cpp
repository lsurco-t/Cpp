#include "BitcoinExchange.hpp"

enum INVALID_FILE {
	IS_EMPTY,
	IS_DIR,
	NOT_EXIST,
	WRONG_EXT,
	WRONG_PERMS
};

bool BitcoinExchange::isValidFile(const std::string& file){
	std::error_code ec;
	auto ext = std::filesystem::path(file).extension();
	auto status = std::filesystem::status(file, ec);
	auto perms = status.permissions();

	if (!std::filesystem::exists(file, ec)){
		return returnErrMessage(NOT_EXIST, file);
	}
	else if ((perms & std::filesystem::perms::owner_read) == std::filesystem::perms::none &&
				(perms & std::filesystem::perms::owner_write) == std::filesystem::perms::none){
		return returnErrMessage(WRONG_PERMS, file);
	}
	else if (ext != ".txt"){
		return returnErrMessage(WRONG_EXT, file);
	}
	else if (std::filesystem::is_directory(file, ec)){
		return returnErrMessage(IS_DIR, file);
	}
	else if (std::filesystem::is_empty(file, ec)){
		return returnErrMessage(IS_EMPTY, file);
	}	
	return true;
}

// unsigned int BitcoinExchange::matchPrice(std::string_view input, std::string_view database){

// }

// void BitcoinExchange::displayOutput(std::string_view input, unsigned int price){

// }

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
		case WRONG_EXT:
			reasonStr = " has wrong extension\n";
			break;
		case WRONG_PERMS:
			reasonStr = " has not enough perms to write or read\n";
	}
	std::cout << "File " << file << reasonStr;
	return false;
}

