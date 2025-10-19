#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <iostream>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void){
	
	std::cout << "\033[32mTesting pointer identification:\033[0m\n";
    for (int i = 0; i < 5; i++) {
        Base* obj = generate();
        identify(obj);
        delete obj;
    }

    std::cout << "\n\033[32mTesting reference identification:\033[0m\n";
    A a;
    B b;
    C c;
	Base some;
    
    identify(a);
    identify(b);
    identify(c);
	identify(some);

	return 0;
}