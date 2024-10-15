#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
template <typename T>
class Matrix{
private:
    void MakeRectangle();
    std::vector<std::vector<T>> data;
public:
    size_t GetRows()const;
    size_t GetColumns()const;
    Matrix(const std::vector<std::vector<T>>&d):data{d} 
    {
		MakeRectangle();
	}
	Matrix(size_t rows,size_t columns)
	{
		data.resize(rows);
		for(auto& row : data )
		{
			row.resize(columns);
		}
	}
	/*const std::vector<T>& operator[] (size_t i)const
	{
		return data[i];
	} 
	std::vector<T>& operator[] (size_t i)
	{
		return data[i];
	}*/
	T& operator() (size_t i,size_t j)
	{
		return data[i][j];
	} 
	const T& operator() (size_t i,size_t j)const
	{
		return data[i][j];
	} 
};


#include "matrix.hpp"
#endif//MATRIX_H
