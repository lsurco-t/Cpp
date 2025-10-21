#include "iter.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"

//Template function to pass as argument
template <typename T>
void print(const T& c){
	std::cout << c << std::endl;
}

//Regular function passed as argument
void increaseOne(const int& num){
	std::cout << num + 1 << std::endl;
}

int main(void){

	std::cout << GREEN "===== First test: Increase numbers by 1 =====" RESET << std::endl;
	int arr[] = {1, 2, 3, 4};
	::iter(arr, std::size(arr), increaseOne);

	std::cout << GREEN "===== Second test: Print every word =====" RESET << std::endl;
	std::string sentence[] = {"This", "is", "a", "sentence"};
	::iter(sentence, std::size(sentence), print);

	return 0;
}