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
	return this->_fixedPoint > other._fixedPoint;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_fixedPoint < other._fixedPoint;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_fixedPoint >= other._fixedPoint;
}
bool Fixed::operator<=(const Fixed& other) const {
	return this->_fixedPoint <= other._fixedPoint;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_fixedPoint == other._fixedPoint;
}

bool Fixed::operator!=(const Fixed& other) const {
	 return this->_fixedPoint != other._fixedPoint;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;

	result._fixedPoint = this->_fixedPoint + other._fixedPoint;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;

	result._fixedPoint = this->_fixedPoint - other._fixedPoint;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;

	result._fixedPoint = ((int64_t)this->_fixedPoint * other._fixedPoint) >> Fixed::_fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	if (other._fixedPoint == 0){
		throw std::runtime_error("Division by 0");
	}
	Fixed result;

	result._fixedPoint = (this->_fixedPoint << Fixed::_fractionalBits) / other._fixedPoint;
	return result;
}

Fixed& Fixed::operator++() {
	_fixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_fixedPoint++;
	return temp;
}

Fixed& Fixed::operator--() {
	_fixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_fixedPoint--;
	return temp;
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