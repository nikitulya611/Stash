#include "Ellipse.h"

Ellipse::Ellipse(double _radiusX, double _radiusY) : radiusX(_radiusX), radiusY(_radiusY) {}

Point3 Ellipse::parFunc(double t) const
{
	return Point3(radiusX * cos(t), radiusY * sin(t), 0);
}

Vector3D Ellipse::derivative(double t) const
{
	return Vector3D(-radiusX * sin(t), radiusY * cos(t), 0);
}
