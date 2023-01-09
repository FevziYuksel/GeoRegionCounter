#include <iostream>

#include "Matrix.h"

template<typename numeral_t>
size_t Matrix<numeral_t>::get_row_size() const
{ 
	return row_size;
};

template<typename numeral_t>
size_t Matrix<numeral_t>::get_col_size() const
{
	return col_size; 
};

template<typename numeral_t>
numeral_t Matrix<numeral_t>::get_pos(const size_t row, const size_t col)
{ 
	return arr[row * row_size + col]; 
};

template<typename numeral_t>
Matrix<numeral_t>::Matrix(const size_t x, const size_t y)
	: row_size{ x }, col_size{ y }, arr{ new numeral_t[x * y]() } {};

template<typename numeral_t>
numeral_t* Matrix<numeral_t>::operator[](const size_t index)
{
	return get_row(index);
}

template<typename numeral_t>
numeral_t* Matrix<numeral_t>::get_row(const size_t index)
{
	return &arr[index % row_size];
}

template<typename numeral_t>
numeral_t* Matrix<numeral_t>::get_row_copy(const size_t index)
{
	const int n = col_size * (index + 1);

	SubArr sub(col_size);

	for (int i = n - col_size, j = 0; i < n; i++, j++)
	{
		sub.sub_arr[j] = this->arr[i];
	}
	return sub.sub_arr;
}

template<typename numeral_t>
Matrix<numeral_t>::~Matrix()
{ 
	delete arr; 
	arr = nullptr; 
}


template<typename numeral_t>
Matrix<numeral_t>::SubArr::SubArr(const size_t size) 
	: sub_arr{ new numeral_t[size]()} {};

template<typename numeral_t>
Matrix<numeral_t>::SubArr::~SubArr() 
{
	delete sub_arr; 
	sub_arr = nullptr; 
};



