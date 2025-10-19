#include <iostream>
#include <random>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 3);

	int result = dist(gen);
	switch (result){
		case 1: 
			return new A();
		case 2:
			return new B();
		case 3:
			return new C();
		default:
			return nullptr;
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "Type of object is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type of object is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type of object is C" << std::endl;
    else std::cout << "Unknown type" << std::endl;
}

void identify(Base& p){
	try {
		dynamic_cast<A&>(p);
		std::cout << "Object is A" << std::endl;
		return ;
	} catch (std::bad_cast&){}

	try {
		dynamic_cast<B&>(p);
		std::cout << "Object is B" << std::endl;
		return ;

	} catch (std::bad_cast&){}

	try {
		dynamic_cast<C&>(p);
		std::cout << "Object is C" << std::endl;
		return ;
	} catch (std::bad_cast&){}

	std::cout << "Unknown type" << std::endl;
}