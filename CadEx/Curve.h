#pragma once

#include <iostream>

const double PI = std::atan(1.0) * 4;

struct Point3 {
	Point3(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {}
	friend std::ostream& operator<<(std::ostream& os, const Point3& p) {
		os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
		return os;
	}
	double x, y, z;
};

class Vector3D {
public:
	Vector3D(Point3 _coordinates) : coordinates(_coordinates) {}
	Vector3D(double x = 0, double y = 0, double z = 0) {
		coordinates.x = x;
		coordinates.y = y;
		coordinates.z = z;
	}

	double length() const {
		return std::sqrt(coordinates.x * coordinates.x + coordinates.y * coordinates.y + coordinates.z * coordinates.z);
	}

	void normalize() {
		double len = length();
		if (len != 0.0) {
			coordinates.x /= len;
			coordinates.y /= len;
			coordinates.z /= len;
		}
	}

	friend std::ostream& operator<<(std::ostream & os, const Vector3D & vec) {
		os << vec.coordinates;
		return os;
	}

private:
	Point3 coordinates;
};

class Curve {
public:
	virtual Point3 parFunc(double t) const = 0;
	virtual Vector3D derivative(double t) const = 0;
};