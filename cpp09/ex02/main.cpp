#include "PmergeMe.hpp"

int main(int argc, char **argv){
	PmergeMe fordJohson;
	std::vector<int> sequence;
	std::chrono::nanoseconds usedTimeVec;
	std::chrono::nanoseconds usedTimeDeq;

	if (!fordJohson.isValidSequence(argc, argv, sequence)){
		return FAILURE;
	}
	
	try {
		usedTimeVec = fordJohson.sortInVector(sequence);
		usedTimeDeq = fordJohson.sortInDeque(sequence);
		fordJohson.displayResults(sequence, fordJohson.getVector(), fordJohson.getDeque(),
			 usedTimeVec, usedTimeDeq);
	} 
	catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	return SUCCESS;
}