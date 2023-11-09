#pragma once

#include "Curve.h"

class Helix : public Curve {
public:
	Helix() = delete;
	Helix(double _radius, double _h);

	Point3 parFunc(double t) const;
	Vector3D derivative(double t) const;

private:
	double radius;
	double h;
};
