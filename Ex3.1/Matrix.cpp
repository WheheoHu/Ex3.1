#pragma once
#include"Matrix.h"

Matrix3by3<float> Matrix_PreMutiply(Matrix3by3<float> maxtri_pre, Matrix3by3<float> matrix)
{
	Matrix3by3<float> temp_matrix;
	auto temp_elem = float();
	for (int row = 0; row < maxtri_pre.getDim_x(); row++)
	{
		for (int col = 0; col < matrix.getDim_y(); col++)
		{
			for (int i = 0; i < maxtri_pre.getDim_y(); i++)
			{
				temp_elem += maxtri_pre.getElem(row, i)*matrix.getElem(i, col);
			}
			temp_matrix.setElem(row, col, temp_elem);
		}
	}
	return temp_matrix;
}

void Matrix_SetIdentity(Matrix3by3<float> maxtrix)
{
	for (unsigned int row = 0; row < maxtrix.getDim_x(); row++)
	{
		for (unsigned int col = 0; col < maxtrix.getDim_y(); col++)
		{
			maxtrix.setElem(row, col, row == col);
		}
	}
}