#include "iter.hpp"
#include <iostream>

#define GREEN "\033[32m"
#define RESET "\033[0m"

//Template function to pass as argument
template <typename T>
void print(const T& c){
	std::cout << c << " ";
}

//Regular function passed as argument
void increaseOne(const int& num){
	std::cout << num + 1;
}

//Function toUpper
void toUpper(const char& c){
	if (c >= 'a' && c <= 'z')
		std::cout << (char)(c - 32);
	else
		std::cout << c ;
}


int main(void){

	std::cout << GREEN "===== First test: Increase numbers by 1 =====" RESET << std::endl;
	int arr[] = {1, 2, 3, 4};
	::iter(arr, std::size(arr), increaseOne);
	std::cout << "\n";

	std::cout << GREEN "===== Second test: Print every word =====" RESET << std::endl;
	std::string sentence[] = {"This", "is", "a", "sentence"};
	::iter(sentence, std::size(sentence), print<std::string>);
	std::cout << "\n";

	std::cout << GREEN "===== Third test: Print every letter =====" RESET << std::endl;
	char word[] = "hello";
	::iter(word, std::size(word), toUpper);
	std::cout << "\n";

	std::cout << GREEN "===== Fourth test: Print floats =====" RESET << std::endl;
	float numbers[] = {3.14f, 2.71f, 1.41f, 1.73f};
	::iter(numbers, std::size(numbers), print<float>);
	std::cout << "\n";

	return 0;
}