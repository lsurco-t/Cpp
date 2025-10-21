#include "whatever.hpp"
#include <iostream>

int main(void){

	int a = 2;
	int b = 3;
	std::cout << "\033[32m======SUBJECT TESTS======\033[0m" << std::endl;
	std::cout << "\n\033[32mParameters:\033[0m" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "\n\033[32mAfter swap\033[0m" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "\033[32mCalculate min and max\033[0m" << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "\n\033[32m======EXTRA TESTS======\033[0m" << std::endl;
	std::cout << "\n\033[32mParameters:\033[0m" << std::endl;
	float nbrOne = 2.4f;
	float nbrTwo = 3.5f;
	std::cout << "f = " << nbrOne << ", g = " << nbrTwo << std::endl;	
	::swap(nbrOne, nbrTwo);
	std::cout << "\n\033[32mAfter swap\033[0m" << std::endl;
	std::cout << "f = " << nbrOne << ", g = " << nbrTwo << std::endl;
	std::cout << "\033[32mCalculate min and max\033[0m" << std::endl;
	std::cout << "min( f, g ) = " << ::min( nbrOne, nbrTwo ) << std::endl;
	std::cout << "max( f, g ) = " << ::max( nbrOne, nbrTwo ) << std::endl << std::endl;
	
	return 0;
}