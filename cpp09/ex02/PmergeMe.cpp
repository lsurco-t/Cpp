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

	std::chrono::duration<double, std::micro> usVectorTime = vecTime;
	std::chrono::duration<double, std::micro> usDequeTime = deqTime;

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
		<< std::fixed << std::setprecision(5) << usVectorTime.count() << " us" << std::endl;
	std::cout << "Time to process a range of " << sortedDq.size() << " with " << "std::deque: " 
		<< std::fixed << std::setprecision(5) << usDequeTime.count() << " us" << std::endl;
}

/*Caller functions to process in each container returning elapsed time*/
std::chrono::nanoseconds PmergeMe::sortInVector(std::vector<int>& input){
	_vect = input;
	auto start = std::chrono::steady_clock::now();
	_vect = fordJohnson(_vect);
	auto stop = std::chrono::steady_clock::now();
	return stop - start;
}

std::chrono::nanoseconds PmergeMe::sortInDeque(std::deque<int>& input){
	_deq = input;
	auto start = std::chrono::steady_clock::now();
	_deq = fordJohnson(_deq);
	auto stop = std::chrono::steady_clock::now();
	return stop - start;
}

/*Functions used to sort the sequence using Vector*/
std::vector<int> PmergeMe::fordJohnson(std::vector<int>& vect){
	if (vect.size() <= 1){
		return vect;
	}

	bool hasStraggler = (vect.size() % 2 != 0);
	int straggler = 0; 

	if (hasStraggler){
		straggler = vect.back();
		vect.pop_back();
	}

	std::vector<std::pair<int, int>> winners;
	for (size_t i = 0; i < vect.size(); i += 2){
		if (vect[i] < vect[i + 1]){
			winners.push_back({vect[i + 1], vect[i]});
		} else {
			winners.push_back({vect[i], vect[i + 1]});
		}
	}

	std::vector<std::pair<int, int>> mainChain = sortPairs(winners);

	std::vector<int> result;
	result.push_back(mainChain[0].second);
	for (const auto& pair: mainChain){
		result.push_back(pair.first);
	}

	if (mainChain.size() > 1){
		std::vector<size_t> insertionOrder = generateJacobsthal(mainChain.size() - 1);
		for (size_t index : insertionOrder){
			binaryInsert(mainChain[index + 1].second, result);
		}
	}
	
	if (hasStraggler){
		binaryInsert(straggler, result);
	}

	return result;
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
	for (size_t i = 0; i < losingPairs.size(); i++){
		binaryInsertPairs(losingPairs[i], sortedPairs);
	}
	if (hasStraggler){
		binaryInsertPairs(straggler, sortedPairs);
 	}
	return sortedPairs;
}

void PmergeMe::binaryInsertPairs(const std::pair<int, int>& pair, std::vector<std::pair<int, int>>& vect){
	auto pos = std::upper_bound(vect.begin(), vect.end(), pair, [](const auto&a, const auto& b) {
		return a.first < b.first;
	});
	vect.insert(pos, pair);
}

void PmergeMe::binaryInsert(int value, std::vector<int>& vect){
	auto pos = std::upper_bound(vect.begin(), vect.end(), value);
	vect.insert(pos, value);
}

/*Functions used to sort the sequence using Deque*/
std::deque<int> PmergeMe::fordJohnson(std::deque<int>& deq){
	if (deq.size() <= 1){
		return deq;
	}

	bool hasStraggler = (deq.size() % 2 != 0);
	int straggler = 0;
	if (hasStraggler){
		straggler = deq.back();
		deq.pop_back();
	}

	std::deque<std::pair<int, int>> winners;
	for (size_t i = 0; i < deq.size(); i += 2){
		if (deq[i] < deq[i + 1]){
			winners.push_back({deq[i + 1], deq[i]});
		} else {
			winners.push_back({deq[i], deq[i + 1]});
		}
	}

	std::deque<std::pair<int, int>> mainChain = sortPairs(winners);

	std::deque<int> result;
	result.push_back(mainChain[0].second);
	for (const auto &pair : mainChain){
		result.push_back(pair.first);
	}

	if (mainChain.size() > 1){
		std::vector<size_t> insertionOrder = generateJacobsthal(mainChain.size() - 1);
		for (size_t index : insertionOrder){
			binaryInsert(mainChain[index + 1].second, result);
		}
	}
	
	if (hasStraggler){
		binaryInsert(straggler, result);
	}
	return result;
}

std::deque<std::pair<int, int>> PmergeMe::sortPairs(std::deque<std::pair<int, int>>& pairs){
	if (pairs.size() <= 1){
		return pairs;
	}

	bool hasStraggler = (pairs.size() % 2 != 0);
	std::pair<int, int> straggler;
	if (hasStraggler){
		straggler = pairs.back();
		pairs.pop_back();
	}

	std::deque<std::pair<int, int>> winningPairs;
	std::deque<std::pair<int, int>> losingPairs;
	for (size_t i = 0; i < pairs.size(); i += 2){
		if (pairs[i].first < pairs[i + 1].first){
			winningPairs.push_back(pairs[i + 1]);
			losingPairs.push_back(pairs[i]);
		} else {
			winningPairs.push_back(pairs[i]);
			losingPairs.push_back(pairs[i + 1]);
		}
	}

	std::deque<std::pair<int, int>> sortedPairs = sortPairs(winningPairs);
	for (size_t i = 0; i < losingPairs.size(); i++){
		binaryInsertPairs(losingPairs[i], sortedPairs);
	}

	if (hasStraggler){
		binaryInsertPairs(straggler, sortedPairs);
	}
	return sortedPairs;
}

void PmergeMe::binaryInsert(int value, std::deque<int>& deq){
	auto pos = std::upper_bound(deq.begin(), deq.end(), value);
	deq.insert(pos, value);
}
void PmergeMe::binaryInsertPairs(const std::pair<int, int>& pair, std::deque<std::pair<int, int>>& deq){
	auto pos = std::upper_bound(deq.begin(), deq.end(), pair, [](const auto& a, const auto& b){
		return a.first < b.first;
	});
	deq.insert(pos, pair);
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t size){
	if (size == 0){
		return {};
	}
	std::vector<size_t> jacobsthal = {0 , 1};
	while (jacobsthal.back() < size){
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}
	std::vector<size_t> insertionOrder;
	std::vector<bool> added(size, false);
	insertionOrder.push_back(0);
	added[0] = true;

	for (size_t i = 3; i < jacobsthal.size(); i++){
		size_t upper = std::min(jacobsthal[i], size);
		size_t lower = jacobsthal[i - 1];

		for (size_t j = upper; j > lower; j--){
			size_t index = j - 1;
			if (index < size && !added[index]){
				insertionOrder.push_back(index);
				added[index] = true;
			}
		}
	}
	for (size_t i = 0; i < size; i++){
		if (!added[i]){
			insertionOrder.push_back(i);
		}
	}
	return insertionOrder;
}

const std::vector<int>& PmergeMe::getVector(void) const {
	return _vect;
}

const std::deque<int>& PmergeMe::getDeque(void) const {
	return _deq;
}

