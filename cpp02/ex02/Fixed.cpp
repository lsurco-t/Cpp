#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0){}

Fixed::Fixed (const Fixed& other) : _fixedPoint(other._fixedPoint){}

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other)
		_fixedPoint = other._fixedPoint;
	return *this;
}

Fixed::~Fixed(){}

int Fixed::getRawBits (void) const {return _fixedPoint;}

void Fixed::setRawBits (int const raw) {_fixedPoint = raw;}

Fixed::Fixed(const int fixedIntPoint) {_fixedPoint = fixedIntPoint << _fractionalBits;}

Fixed::Fixed(const float floatPoint) {_fixedPoint = roundf(floatPoint * (1 << _fractionalBits));}

float Fixed::toFloat(void) const {return (float) _fixedPoint / (1 << _fractionalBits);}

int Fixed::toInt(void) const {return _fixedPoint >> _fractionalBits;}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& other) const {

}

bool Fixed::operator<(const Fixed& other) const {

}

bool Fixed::operator>=(const Fixed& other) const {


}
bool Fixed::operator<=(const Fixed& other) const {

}

bool Fixed::operator==(const Fixed& other) const {

}

bool Fixed::operator!=(const Fixed& other) const {

}

Fixed Fixed::operator+(const Fixed& other) const {

}

Fixed Fixed::operator-(const Fixed& other) const {

}

Fixed Fixed::operator*(const Fixed& other) const {

}

Fixed Fixed::operator/(const Fixed& other) const {

}

Fixed& Fixed::operator++() {

}

Fixed Fixed::operator++(int) {

}

Fixed& Fixed::operator--() {

}

Fixed Fixed::operator--(int) {

}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}