#ifndef CONE_H
#define CONE_H

#include <cmath>
#include "Circle.h"

class Cone : public Circle {
	public:
		Cone() = default;
		explicit Cone(double radius, double height) : Circle(radius), height(height) {}
		const double area() const override {
			return pi * pow(radius, 2) + pi * radius * sqrt(pow(radius, 2) + pow(height, 2));
		}
		const double volume() const override {
			return 1 / 3 * pi * pow(radius, 2) * height;
		}
	private:
		double height = 0.0;
};
#endif
