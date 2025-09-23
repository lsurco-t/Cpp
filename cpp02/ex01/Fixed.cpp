#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed (const Fixed& other) : _fixedPoint(other._fixedPoint){
	std::cout << "Copy constructor called\n";
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

Fixed::Fixed(const int fixedIntPoint){
	std::cout << "Int constructor called\n";
	_fixedPoint = fixedIntPoint << _fractionalBits;
}

Fixed::Fixed(const float floatPoint){
	std::cout << "Float constructor called\n";
	_fixedPoint = roundf(floatPoint * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const {
	return (float) _fixedPoint / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _fixedPoint >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}