#pragma once
#include"Matrix.h"

Matrix3by3<float> Matrix_PreMutiply(Matrix3by3<float> maxtri_pre, Matrix3by3<float> matrix)
{
	Matrix3by3<float> temp_matrix;
	float temp_elem = 0;
	for (int row = 0; row < maxtri_pre.getDim_x(); row++)
	{
		for (int col = 0; col < matrix.getDim_y(); col++)
		{
			for (int i = 0; i < maxtri_pre.getDim_y(); i++)
			{
				temp_elem += maxtri_pre.getElem(row, i)*matrix.getElem(i, col);
			}
			temp_matrix.setElem(row, col, temp_elem);
			temp_elem = 0;
		}
	}
	return temp_matrix;
}

Matrix3by3<float> Translate2D(float tx, float ty, Matrix3by3 < float> mat_input)
{
	Matrix3by3 <float> mat_translate;
	mat_translate=Matrix_SetIdentity(mat_translate);
	mat_translate.setElem(0, 2, tx);
	mat_translate.setElem(1, 2, ty);
	return Matrix_PreMutiply(mat_translate, mat_input);

}

Matrix3by3<float> Scale2D(float sx, float sy, Point2D<int> fixedPt, Matrix3by3 < float> mat_input)
{
	Matrix3by3 <float> mat_scale;
	mat_scale=Matrix_SetIdentity(mat_scale);
	mat_scale.setElem(0, 0, sx);
	mat_scale.setElem(1, 1, sy);
	return Translate2D(fixedPt.getcoorX(), fixedPt.getcoory(), Matrix_PreMutiply(mat_scale, Translate2D(-fixedPt.getcoorX(), -fixedPt.getcoory(), mat_input)));

}

Matrix3by3<float> Rotate2D(Point2D<int> fixedPt, float theta, Matrix3by3<float> mat_input)
{

	Matrix3by3 <float> mat_rotate;
	mat_rotate=Matrix_SetIdentity(mat_rotate);
	mat_rotate.setElem(0, 0, std::cos(theta));
	mat_rotate.setElem(0, 1, -std::sin(theta));
	mat_rotate.setElem(1, 0, std::sin(theta));
	mat_rotate.setElem(1, 1, std::cos(theta));
	return Translate2D(fixedPt.getcoorX(), fixedPt.getcoory(), Matrix_PreMutiply(mat_rotate, Translate2D(-fixedPt.getcoorX(), -fixedPt.getcoory(), mat_input)));

}


Matrix3by3<float> Matrix_SetIdentity(Matrix3by3<float> maxtrix)
{
	for (unsigned int row = 0; row < maxtrix.getDim_x(); row++)
	{
		for (unsigned int col = 0; col < maxtrix.getDim_y(); col++)
		{
			maxtrix.setElem(row, col, row == col);
		}
	}
	return maxtrix;
}