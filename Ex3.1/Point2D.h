#pragma once
template <typename T>
class Point2D
{
public:
	Point2D(const T x_, const T y_);
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