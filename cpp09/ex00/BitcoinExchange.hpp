#pragma once
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <map>

class BitcoinExchange{

	private:
		std::map<int, int> _trades;

	public:
		BitcoinExchange() = default;
		BitcoinExchange(const BitcoinExchange& other) = default;
		BitcoinExchange& operator=(const BitcoinExchange& other) = default;
		~BitcoinExchange() = default;

		bool 			isValidFile(std::string& file);
		unsigned int	matchPrice(std::string_view input, std::string_view database);
		void 			displayOutput(std::string_view input, unsigned int price);
};