#ifdef SPHERE_H
#define SPHERE_H

#include <cmath>
#include "Circle.h"

class Sphere : public Circle {
	public:
		Sphere() = default;
		explicit Sphere(double radius) : Circle(radius) {}
		const double area() const override {
			return 4 * pi * pow(radius, 2);
		}
		const double volume() const override {
			return 4 / 3 * pi * pow(radius, 3);
		}
};
#endif
