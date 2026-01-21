#pragma once
#include <deque>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <chrono>

// General error codes return
constexpr int FAILURE = 1;
constexpr int SUCCESS = 0;

class PmergeMe {

	private:
		std::vector<int> _vect;
		std::deque<int>	_deq;

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