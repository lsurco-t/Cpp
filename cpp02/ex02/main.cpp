#include <iostream>
#include "Fixed.hpp"

int main ( void ) {

	Fixed d;
	Fixed const e( 10 );
	Fixed const f( 42.42f );
	Fixed const g( e );

	d = Fixed( 1234.4321f );

	std::cout << "\033[31mFirst part testing previous functionality:\033[0m\n";
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << "g is " << g << std::endl;

	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << "f is " << f.toInt() << " as integer" << std::endl;
	std::cout << "g is " << g.toInt() << " as integer" << std::endl;

	std::cout << "\033[31mSecond part testing ex02 functionality:\033[0m\n";
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const o( Fixed (5.67f) / Fixed (5));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << o << std::endl;

	return 0;
}