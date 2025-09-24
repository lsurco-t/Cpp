#include <iostream>
#include <iomanip>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void tests
(const Point&a, const Point& b, const Point& c,
	 const Point& p, bool expected, const std::string& label){

		std::cout << label << ": ";
		bool result = bsp(a, b, c, p);

		if (result)
			std::cout << "inside";
		else
			std::cout << "outside";
			
		if (result == expected)
			std::cout << " ✅" << std::endl;
		else
			std::cout << " ❌ (expected " << (expected ? "inside" : "outside") << ")" << std::endl;

}

int main (void){

	std::cout << std:: fixed << std::setprecision(2);
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.25f);
	
	tests(a, b, c, Point(4.0f, 5.0f), true,  "Test 1 - Strictly inside");
	tests(a, b, c, Point(5.0f, 10.25f), false, "Test 2 - On vertex C");
	tests(a, b, c, Point(5.0f, 0.0f), false,   "Test 3 - On base edge AB");
	tests(a, b, c, Point(10.0f, 10.0f), false, "Test 4 - Outside triangle");
	tests(a, b, c, Point(5.0f, 5.0f), true,    "Test 5 - Strictly inside");
	tests(a, b, c, Point(0.0f, 0.0f), false,   "Test 6 - On vertex A");

	return 0;
}