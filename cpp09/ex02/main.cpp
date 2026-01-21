#include "PmergeMe.hpp"

int main(int argc, char **argv){
	PmergeMe fordJohnson;
	std::vector<int> sequence;
	std::deque<int> sequenceDeq;
	std::chrono::nanoseconds usedTimeVec;
	std::chrono::nanoseconds usedTimeDeq;

	if (argc == 1){
		std::cerr << "Error: Empty sequence" << std::endl;
		return FAILURE;
	}

	if (!fordJohnson.isValidSequence(argc, argv, sequence, sequenceDeq)){
		return FAILURE;
	}
	
	try {
		usedTimeVec = fordJohnson.sortInVector(sequence);
		usedTimeDeq = fordJohnson.sortInDeque(sequenceDeq);
		fordJohnson.displayResults(sequence, fordJohnson.getVector(), fordJohnson.getDeque(),
			 usedTimeVec, usedTimeDeq);
	} 
	catch (std::exception &e){
		std::cerr << "Error: " << e.what() << std::endl;
		return FAILURE;
	}
	
	return SUCCESS;
}