#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv){

	if (argc != 4) {
		std::cout << "Only 3 arguments please, thank you\n";
		return 1;
	}

	std::string inputFileName = argv[1];
	std::string findStr = argv[2];
	std::string replaceWithStr = argv[3];
	std::string outputFileName = inputFileName + ".replace";

	if (findStr.empty()) {
		std::cout << "Error: string to find cannot be empty\n";
		return 1;
	}

	std::ifstream inputFile(inputFileName);
	if (!inputFile){
		std::cout << "Failed to open " << inputFileName << std::endl;
		return 1;
	}

	std::ofstream outputFile(outputFileName);
	if (!outputFile){
		std::cout << "Failed to create " << outputFileName << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inputFile, line)){
		std::string newLine;
		size_t i = 0;

		while (i < line.length()){
			if(line.substr(i, findStr.length()) == findStr){
				newLine += replaceWithStr;
				i += findStr.length();
			}
			else{
				newLine += line[i];
				i++;
			}
		}
			outputFile << newLine << "\n";
	}
	inputFile.close();
	outputFile.close();
	return 0;
}