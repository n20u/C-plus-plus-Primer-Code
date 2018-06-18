#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>

static const double pi = 3.14;

class Circle {
	public:
		Circle() = default;
		explicit Circle(double radius) : radius(radius) {}
		virtual const double area() const {
			return pi * pow(radius, 2);
		}
		virtual const double volume() const {
			return 0;
		}
		virtual ~Circle() = default; 
	protected:
		double radius = 0;
};

#endif
