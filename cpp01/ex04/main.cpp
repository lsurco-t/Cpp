#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv){

	if (argc != 4) {
		std::cout << "Only 3 arguments please, thank you";
		return 1;
	}

	std::string inputFileName = argv[1];
	std::string findStr = argv[2];
	std::string replaceWithStr = argv[3];
	std::string outputFileName = inputFileName + ".replace";

	


	return 0;
}