#pragma once
#include <deque>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <chrono>
#include <algorithm>
#include <iomanip>

// General error codes return
constexpr int FAILURE = 1;
constexpr int SUCCESS = 0;

class PmergeMe {

	private:
		std::vector<int> _vect;
		std::deque<int>	_deq;

		std::vector<int> fordJohnson(std::vector<int>& vect);
		std::vector<std::pair<int, int>> sortPairs(std::vector<std::pair<int, int>>& pairs);
		void binaryInsert(int value, std::vector<int>& vect);
		void binaryInsertPairs(const std::pair<int, int>& pair, std::vector<std::pair<int, int>>& vect);
		

		std::deque<int> fordJohnson(std::deque<int>& deq);
		std::deque<std::pair<int, int>> sortPairs(std::deque<std::pair<int, int>>& pairs);
		void binaryInsert(int value, std::deque<int>& deq);
		void binaryInsertPairs(const std::pair<int, int>& pair, std::deque<std::pair<int, int>>& deq);

		std::vector<size_t> generateJacobsthal(size_t size);

	public:
		PmergeMe() = default;
		PmergeMe(const PmergeMe& other) = delete;
		PmergeMe& operator=(const PmergeMe other) = delete;
		~PmergeMe() = default;

		bool isValidSequence(int argc, char **argv, std::vector<int>& vector, std::deque<int>& deque);
		std::chrono::nanoseconds sortInVector(std::vector<int>& input);
		std::chrono::nanoseconds sortInDeque(std::deque<int>& input);
		void displayResults(std::vector<int>& unsorted, const std::vector<int>& sortedV, 
				const std::deque<int>& sortedDq, std::chrono::nanoseconds& vecTime, 
					std::chrono::nanoseconds& deqTime);
		const std::vector<int>& getVector(void) const;
		const std::deque<int>& getDeque(void) const;

};