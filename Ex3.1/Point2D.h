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


std::vector<Point2D<int>> translatePoint2D(Matrix3by3<float> mat_composed, std::vector<Point2D<int>> PointData) {
	std::vector<Point2D<int>> PointData_trans;

	float temp_elem_x = 0, temp_elem_y = 0;
	for (auto iter = PointData.begin(); iter != PointData.end(); iter++)
	{
			
				temp_elem_x = mat_composed.getElem(0, 0)*iter->getcoorX()+ mat_composed.getElem(0, 1)*iter->getcoory()+ mat_composed.getElem(0, 2);
				temp_elem_y = mat_composed.getElem(1, 0)*iter->getcoorX() + mat_composed.getElem(1, 1)*iter->getcoory() + mat_composed.getElem(1, 2);
			PointData_trans.push_back(Point2D<int>(temp_elem_x, temp_elem_y));
			temp_elem_x = 0;
			temp_elem_y = 0;
	}
}