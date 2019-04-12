#pragma once
#include<vector>
#include"Matrix3by3.h"
#include"Point2D.h"

Matrix3by3<float> Matrix_SetIdentity(Matrix3by3<float> maxtrix);
Matrix3by3<float> Matrix_PreMutiply(Matrix3by3<float> maxtri_pre, Matrix3by3<float> matrix);
Matrix3by3<float> Translate2D(float fx, float fy, Matrix3by3 < float> mat_input);
Matrix3by3<float> Scale2D(float sx, float sy, Point2D<int> fixedPt, Matrix3by3 < float> mat_input);
Matrix3by3<float> Rotate2D(Point2D<int> fixedPt, float theta, Matrix3by3 < float> mat_input);