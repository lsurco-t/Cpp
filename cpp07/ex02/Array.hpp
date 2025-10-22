#pragma once

template<typename T>
class Array{

	private:
		T* _array;
		unsigned int _size;

	public:
		Array();
		Array(const Array<T>& other);
		Array<T>& operator=(const Array<T>& other);
		~Array();

		Array(unsigned n);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size(void);
};

#include "Array.tpp"