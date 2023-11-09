#pragma once

#include "Curve.h"

class Circle : public Curve {
public:
	Circle() = delete;
	explicit Circle(double _radius);

	Point3 parFunc(double t) const;
	Vector3D derivative(double t) const;

	double getRadius() const;
private:
	double radius;
};
