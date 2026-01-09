#pragma once
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <map>

// General error codes return
constexpr int FAILURE = 1;
constexpr int SUCCESS = 0;

class BitcoinExchange{

	private:
		std::map<std::string, double> _database;
		
	public:
		BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange& other) = default;
		BitcoinExchange& operator=(const BitcoinExchange& other) = default;
		~BitcoinExchange() = default;

		bool 	returnErrMessage(unsigned int reason, const std::string& file);
		bool	isValidFile(const std::string& filename);
		bool	isValidDate(const std::string& date);
		void	loadDatabase(const std::string& filename);
		void 	processLine(const std::string& line);
		double	getExchangeRate(const std::string& date) const;
};