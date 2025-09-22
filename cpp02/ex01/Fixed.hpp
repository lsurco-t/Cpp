#pragma once

class Fixed {

	private:

	public:
		Fixed(const int fixedPoint);
		Fixed(const float floatPoint);
		~Fixed();

		float toFloat(void) const;
		int toInt(void) const;

};