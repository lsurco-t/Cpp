#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main (void){

	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.25f);
	
	Point p(4.0f, 5.0f);

	std::cout << "A values: " << a.getX() << ", " << a.getY() << std::endl;
	std::cout << "B values: " << b.getX() << ", " << b.getY() << std::endl;
	std::cout << "C values: " << c.getX() << ", " << c.getY() << std::endl;
	std::cout << "P values: " << p.getX() << ", " << p.getY() << std::endl;

	if (bsp(a, b, c, p))
		std::cout << "Point is inside triangle!\n";
	else
		std::cout << "Point is outside triable\n";
	return 0;
}