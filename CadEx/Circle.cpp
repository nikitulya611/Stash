#include "Circle.h"


Circle::Circle(double _radius) : radius(_radius)
{
}

Point3 Circle::parFunc(double t) const
{
	return Point3(radius * cos(t), radius * sin(t), 0);
}

Vector3D Circle::derivative(double t) const
{
	return Vector3D(-radius * sin(t), radius * cos(t), 0);
}

double Circle::getRadius() const
{
	return radius;
}
