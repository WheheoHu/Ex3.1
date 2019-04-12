#pragma once
template <typename T>
class Matrix3by3
{
public:
	Matrix3by3()
		:
		dimx(3),
		dimy(3)
	{
		inner.resize(dimx*dimy);
	}

	//forget this
	Matrix3by3(unsigned int dimx_, unsigned int dimy_)
		:
		dimx(dimx_),
		dimy(dimy_)
	{
		inner.resize(dimx*dimy);
	}
	int getDim_x()
	{
		return dimx;
	}
	int getDim_y()
	{
		return dimy;
	}
	T& getElem(unsigned int x, unsigned int y);
	void setElem(unsigned int x, unsigned int y, T Elem);

private:
	 std::vector<T> inner;
	unsigned int dimx, dimy;
};

template<typename T>
T & Matrix3by3<T>::getElem(unsigned int x, unsigned int y)
{
	if (x >= dimx || y >= dimy)
	{
		throw std::out_of_range("Matrix out of range");
	}
	return inner[dimx*y + x];
}

template<typename T>
void Matrix3by3<T>::setElem(unsigned int x, unsigned int y, T Elem)
{
	if (x >= dimx || y >= dimy)
	{
		throw std::out_of_range("Matrix out of range");
	}
	inner[dimx*y + x] = Elem;
}
