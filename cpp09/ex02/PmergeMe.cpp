#include "PmergeMe.hpp"

bool PmergeMe::isValidSequence(int argc, char **argv, std::vector<int>& vector, std::deque<int>& deque){
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
		vector.push_back(number);
	}
	deque.assign(vector.begin(), vector.end());
	return true;
}

void PmergeMe::displayResults(std::vector<int>& unsorted, const std::vector<int>& sortedV,
	 const std::deque<int>& sortedDq, std::chrono::nanoseconds& vecTime, std::chrono::nanoseconds& deqTime ){
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
		<< vecTime.count() << " ns" << std::endl;
	std::cout << "Time to process a range of " << sortedDq.size() << " with " << "std::deque: " 
		<< deqTime.count() << " ns" << std::endl;
}

std::chrono::nanoseconds PmergeMe::sortInVector(std::vector<int>& input){
	auto start = std::chrono::steady_clock::now();
	_vect = input;
	_vect = fordJohnson(_vect);
	auto stop = std::chrono::steady_clock::now();
	return stop - start;
}

std::chrono::nanoseconds PmergeMe::sortInDeque(std::deque<int>& input){
	auto start = std::chrono::steady_clock::now();
	_deq = input;
	_deq = fordJohnson(_deq);
	auto stop = std::chrono::steady_clock::now();
	return stop - start;
}

std::vector<int> PmergeMe::fordJohnson(std::vector<int>& vect){
	if (vect.size() <= 1){
		return vect;
	}

	bool hasStraggler = (vect.size() % 2 != 0);
	int straggler = 0; // Last number in the sequence in case it is odd size

	if (hasStraggler){
		straggler = vect.back(); // Saves the last element before comparing in pairs
		vect.pop_back();
	}

	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i < vect.size(); i += 2){
		if (vect[i] < vect[i + 1]){
			pairs.push_back({vect[i + 1], vect[i]});
		} else {
			pairs.push_back({vect[i], vect[i + 1]});
		}
	}

	std::vector<std::pair<int, int>> sortedPairs = sortPairs(pairs);

	std::vector<int> mainChain;
	for (auto& winner : sortedPairs){
		mainChain.push_back(winner.first);
	}



	return mainChain;
}

std::vector<std::pair<int, int>> PmergeMe::sortPairs(std::vector<std::pair<int, int>>& pairs){
	if (pairs.size() <= 1){
		return pairs;
	}

	bool hasStraggler = (pairs.size() % 2 != 0);
	std::pair<int, int> straggler;
	if (hasStraggler){
		straggler = pairs.back();
		pairs.pop_back();
	}

	std::vector<std::pair<int, int>> winningPairs;
	std::vector<std::pair<int, int>> losingPairs;

	for (size_t i = 0; i < pairs.size(); i +=2){
		if (pairs[i].first < pairs[i + 1].first){
			winningPairs.push_back(pairs[i + 1]);
			losingPairs.push_back(pairs[i]);
		} else {
			winningPairs.push_back(pairs[i]);
			losingPairs.push_back(pairs[i + 1]);
		}
	}
	
	std::vector<std::pair<int, int>> sortedPairs = sortPairs(winningPairs);

	if (hasStraggler){

	}

	return sortedPairs;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t size){
	if (size == 0){
		return;
	}
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	size_t index = 2;
	while (jacobsthal.back() < size){
		size_t next = jacobsthal[index - 1] + 2 * jacobsthal[index - 2];
		jacobsthal.push_back(next);
		index++;
	}
	std::vector<size_t> insertionOrder;
	for (size_t i = 3; i < jacobsthal.size(); i++){
		size_t start = jacobsthal[i];
		size_t end = jacobsthal[i - 1];

		for (size_t j = start; j > end; j--){
			if (j - 1 < size){
				insertionOrder.push_back(j - 1);
			}
		}
	}

	return insertionOrder;
}

void PmergeMe::binaryInsert(int value, std::vector<int>& vect){

}

void PmergeMe::binaryInsertPairs(const std::pair<int, int>& pair, std::vector<std::pair<int, int>>& vect){

}

std::deque<int> PmergeMe::fordJohnson(std::deque<int>& deq){

}

const std::vector<int>& PmergeMe::getVector(void) const {
	return _vect;
}

const std::deque<int>& PmergeMe::getDeque(void) const {
	return _deq;
}

