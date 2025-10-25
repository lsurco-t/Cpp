#include "MutantStack.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

void variedTests(unsigned int testNumber){
	switch (testNumber){
		case 1: {
			std::cout << GREEN "=====Test 1: Subject's test =====" RESET << std::endl;
			MutantStack<int> mstack;

			mstack.push(5);
			mstack.push(17);

			std::cout << "Top of stack number: " << mstack.top() << std::endl;
			mstack.pop(); //used to remove the top element from the stack

			std::cout << "Stack size is: " << mstack.size() << std::endl;

			mstack.push(3);
			mstack.push(5);
			mstack.push(737);
			//[...]
			mstack.push(0);

			MutantStack<int>::iterator it = mstack.begin();
			MutantStack<int>::iterator ite = mstack.end();

			++it;
			--it;
			while (it != ite){
				std::cout << *it << std::endl;
				++it;
			}

			std::stack<int> s(mstack);
			break;
		}

		case 2: { // Const iteration test
			std::cout << GREEN "=====Test 2: Const iterator test =====" RESET << std::endl;
			MutantStack<int> mstack;
			for (int i = 1; i <= 5; ++i)
				mstack.push(i);

			const MutantStack<int>& cmstack = mstack;
			std::cout << "Elements using const_iterator:" << std::endl;
			for (MutantStack<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); ++it)
				std::cout << *it << std::endl;

			break;
		}

		case 3: { // Reverse iteration
			std::cout << GREEN "=====Test 3: Reverse iteration =====" RESET << std::endl;
			MutantStack<int> mstack;
			for (int i = 10; i <= 50; i += 10)
				mstack.push(i);

			std::cout << "Elements in reverse:" << std::endl;
			MutantStack<int>::iterator it = mstack.end();
			while (it != mstack.begin()) {
				--it;
				std::cout << *it << std::endl;
			}

			break;
		}

		case 4: { // Using MutantStack with strings
			std::cout << GREEN "=====Test 4: String stack test =====" RESET << std::endl;
			MutantStack<std::string> mstack;
			mstack.push("Hello");
			mstack.push("Mutant");
			mstack.push("Stack");

			std::cout << "Top element: " << mstack.top() << std::endl;

			std::cout << "All elements:" << std::endl;
			for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
				std::cout << *it << std::endl;

			break;
		}

		case 5: { // Algorithm test (std::find)
			std::cout << GREEN "=====Test 5: STL algorithm test =====" RESET << std::endl;
			MutantStack<int> mstack;
			for (int i = 1; i <= 10; ++i)
				mstack.push(i);

			MutantStack<int>::iterator it = std::find(mstack.begin(), mstack.end(), 7);
			if (it != mstack.end())
				std::cout << "Found 7 in the stack!" << std::endl;
			else
				std::cout << "7 not found!" << std::endl;

			break;
		}

		default:
			break;
	}
}

int main(void){
	for (size_t i = 1; i < 6; i++)
		variedTests(i);
	return 0;
}