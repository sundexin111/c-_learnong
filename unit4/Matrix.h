#ifndef _Matrix_H_
#define _Matrix_H_

#include<iostream>

using namespace std;

typedef float elemType;

class Matrix
{
	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator*(const Matrix&, const Matrix&);
public:
    
	Matrix(const elemType*);
	Matrix(elemType = 0., elemType = 0., elemType = 0., elemType = 0.,
		   elemType = 0., elemType = 0., elemType = 0., elemType = 0.,
		   elemType = 0., elemType = 0., elemType = 0., elemType = 0.,
		   elemType = 0., elemType = 0., elemType = 0., elemType = 0.);

	int rows() const { return 4; }
	int cols() const { return 4; }

	//ostream是非标准输出，cout只能输出int,double等
	ostream& print(ostream&) const;
	void operator+=(const Matrix&);
	elemType operator()(int row,int column) const
	{
		return _matrix[row][column];
	}

	elemType& operator()(int row, int column) 
	{
		return _matrix[row][column];
	}

private:
	elemType _matrix[4][4];
};

//print用到了类中的成员函数，所以定义为inline
inline ostream& operator<<(ostream& os, const Matrix &m) { return m.print(os); }


#endif