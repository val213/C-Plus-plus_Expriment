#ifndef MARRIX_H
#define MARRIX_H
#include<iostream>
using std::ostream;
using std::istream;
using namespace std;
class Matrix
{
	friend ostream& operator << (ostream&,const Matrix&);
	friend istream& operator >> (istream&, Matrix&);
public:
	Matrix();
	Matrix(int,int,int,int);
	const Matrix& operator+( Matrix&);
	const Matrix& operator-(const Matrix&);
	const Matrix& operator*(const Matrix&);
	const Matrix& operator*(int);
	const Matrix& operator=(const Matrix&);
	const Matrix& operator+=(const Matrix&);
	const Matrix& operator-=(const Matrix&);
	const Matrix& operator*=(const Matrix&);
	const Matrix& operator*=(int);
	bool operator ==(const Matrix&)const;
	bool operator !=(const Matrix&)const;
private:
	int a = 1;
	int b = 0;
	int c = 0;
	int d = 1;
};
#endif
