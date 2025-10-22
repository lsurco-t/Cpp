#pragma once

template<typename T>
class Array{

	private:

	public:
		Array(T[]);
		Array(unsigned n, T[n]);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
};