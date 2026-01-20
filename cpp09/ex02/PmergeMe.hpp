#pragma once
#include <deque>
#include <vector>
#include <iostream>
#include <string>

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

		bool isValidSequence(int argc, const char **argv, std::vector<int> input);
		void fordJohnsonVect(std::vector<int>& vect);
		void fordJohnsonDeq(std::deque<int>& deq);

};