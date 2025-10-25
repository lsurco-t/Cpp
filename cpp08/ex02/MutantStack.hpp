#pragma once
#include <algorithm>
#include <climits>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>{

	public:
		MutantStack();
		MutantStack(const MutantStack<T>& other);
		MutantStack<T>& operator=(const MutantStack<T>& other);
		~MutantStack();
		
};

#include "MutantStack.tpp"