#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
using std::ostream;
using std::istream;
using namespace std;

class Matrix
{
	friend ostream& operator<<(ostream&, const Matrix&); // 友元流输出运算符重载
	friend istream& operator>>(istream&, Matrix&);       // 友元流输入运算符重载

public:
	Matrix();                                           // 默认构造函数
	Matrix(int, int, int, int);                         // 带参构造函数

	const Matrix& operator+(Matrix&);                    // 加法运算符重载
	const Matrix& operator-(const Matrix&);              // 减法运算符重载
	const Matrix& operator*(const Matrix&);              // 乘法运算符重载
	const Matrix& operator*(int);                        // 乘法运算符重载（与整数相乘）
	const Matrix& operator=(const Matrix&);              // 赋值运算符重载
	const Matrix& operator+=(const Matrix&);             // 复合加法赋值运算符重载
	const Matrix& operator-=(const Matrix&);             // 复合减法赋值运算符重载
	const Matrix& operator*=(const Matrix&);             // 复合乘法赋值运算符重载
	const Matrix& operator*=(int);                       // 复合乘法赋值运算符重载（与整数相乘）
	bool operator==(const Matrix&) const;                // 相等运算符重载
	bool operator!=(const Matrix&) const;                // 不相等运算符重载

private:
	int a = 1;                                          // 矩阵元素 a
	int b = 0;                                          // 矩阵元素 b
	int c = 0;                                          // 矩阵元素 c
	int d = 1;                                          // 矩阵元素 d
};

#endif
