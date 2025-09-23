#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed (const Fixed& other){
	std::cout << "Copy constructor called\n";
	_fixedPoint = other._fixedPoint;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		_fixedPoint = other._fixedPoint;
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits (void) const{
	std::cout << "getRawBits member function called\n";
	return _fixedPoint;
}

void Fixed::setRawBits (int const raw){
	_fixedPoint = raw;
}

Fixed::Fixed(const int fixedPoint){

}

Fixed::Fixed(const float floatPoint){

}

float Fixed::toFloat(void) const {

}

int Fixed::toInt(void) const {

}
