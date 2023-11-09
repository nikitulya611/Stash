#include "Helix.h"

Helix::Helix(double _radius, double _h)	: radius(_radius), h(_h) {}

Point3 Helix::parFunc(double t) const
{
	return Point3(radius * cos(t), radius * sin(t), h * t / (2 * PI));
}

Vector3D Helix::derivative(double t) const
{
	return Vector3D(-radius * sin(t), radius * cos(t), h / (2 * PI));
}