#include "PmergeMe.hpp"

int main(int argc, char **argv){
	PmergeMe fordJohson;
	std::vector<int> sequence;

	if (!fordJohson.isValidSequence(argc, argv, sequence)){
		return FAILURE;
	}
	
	return SUCCESS;
}