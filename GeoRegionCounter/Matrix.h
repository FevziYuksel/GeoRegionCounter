#pragma once

template<typename numeral_t>
class Matrix
{
public:

	const size_t matrix_size;

	Matrix() = delete; //Default constructor is deleted

	Matrix(const Matrix& matrix) = delete; //Copy constructor is deleted
	
	size_t get_row_size() const;

	size_t get_col_size() const;

	numeral_t get_pos(const size_t row, const size_t col);

	//same calls get_row
	numeral_t* operator[](const size_t index);

	//Possible memory safety risk( return C array) 
	numeral_t* get_row(const size_t index);

	//Create transition array size of simulated sub array
	numeral_t* get_row_copy(const size_t index);

	Matrix(const size_t x, const size_t y);

	~Matrix();

private:

	const size_t row_size;

	const size_t col_size;

	numeral_t* arr;

	struct SubArr
	{
		numeral_t* sub_arr;

		SubArr(const size_t size);

		~SubArr();
	};
};



