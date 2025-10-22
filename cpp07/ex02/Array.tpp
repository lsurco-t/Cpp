#include "Array.hpp"

template<typename T>
Array<T>::Array(): _array[nullptr], _size(0){}

template<typename T>
Array<T>::Array(const Array& other){

}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){

}

template<typename T>
Array<T>::~Array(){
	delete[] _array;
}

template<typename T>
Array<T>::Array(unsigned n): _array(new T[n]), _size(n){}

template<typename T>
T& Array<T>::operator[](unsigned int index){
	if (index >= _index)
		throw std::exception("Out of bounds!")
	return T& _array[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const{
	if (index >= _index)
		throw std::exception("Out of bounds!")
	return _array[index];
}

template<typename T>
unsigned int Array<T>::size(void){
	return _size;
}