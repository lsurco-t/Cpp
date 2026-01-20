#include "PmergeMe.hpp"

bool PmergeMe::isValidSequence(int argc, char **argv, std::vector<int>& input){
	std::set<int> seen;
	for (int i = 1; i < argc; i++){
		int number;
		size_t pos;
		try {
			number = std::stoi(argv[i], &pos);
			if (pos != std::strlen(argv[i])){
				std::cerr << "Error: " << argv[i] << " not accepted" << std::endl;
				return false;
			}
			if (number < 0){
				std::cerr << "Error: " << number << " is negative" << std::endl;
				return false;
			}
			if (!seen.insert(number).second){
				std::cerr << "Error: " << number << " already exists" << std::endl;
				return false;
			}
		} catch (...){
			std::cerr << "Error: " << argv[i] << " is not a valid value" << std::endl;
			return false;
		}
		input.push_back(number);
	}
	return true;
}

void PmergeMe::displayResults(std::vector<int> unsorted, std::vector<int> sortedV, std::deque<int> sortedDq){
	std::cout << "Before: ";
	for (auto i : unsorted){
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for (auto i : sortedV){
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << sortedV.size() << " with " << "std::vector: "
		"time " << std::endl;
	std::cout << "Time to process a range of " << sortedDq.size() << " with " << "std::deque: "
		"time " << std::endl;
}

void PmergeMe::fordJohnsonVect(std::vector<int>& vect){

}

void PmergeMe::fordJohnsonDeq(std::deque<int>& deq){

}


