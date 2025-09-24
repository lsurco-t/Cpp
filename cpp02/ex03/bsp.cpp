#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

static Fixed wedgeProduct(const Point& a, const Point& b, const Point& c){
	return (b.getX() - a.getX()) * (c.getY() - a.getY()) - 
	       (b.getY() - a.getY()) * (c.getX() - a.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed ab = wedgeProduct(a, b, point);
	Fixed bc = wedgeProduct(b ,c, point);
	Fixed ca = wedgeProduct(c, a, point);

	return ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0));
}