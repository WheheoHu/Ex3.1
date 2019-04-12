#pragma once

#include"Matrix.h"

template <typename T>
class Point2D
{
public:
	Point2D(const T x_, const T y_) :
		x(x_),
		y(y_)
	{
	}
	T getcoorX() {
		return x;
	}
	T getcoory() {
		return y;
	}
private:
	const T x;
	const T y;
};


