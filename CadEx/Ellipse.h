#pragma once

#include "Curve.h"

class Ellipse : public Curve {
public:
	Ellipse() = delete;
	explicit Ellipse(double _radiusX, double _radiusY);

	Point3 parFunc(double t) const;
	Vector3D derivative(double t) const;

private:
	double radiusX, radiusY;
};
