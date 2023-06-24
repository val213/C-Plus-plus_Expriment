#include<iostream>
#include<iomanip>
#include"Matrix.h"
using std::ostream;
using std::istream;
using namespace std;

// 重载流输出运算符 <<
ostream& operator<<(ostream& output, const Matrix& m)
{
	cout << "print matrix" << endl;
	output << m.a << " " << m.b << "\n";
	output << m.c << " " << m.d << "\n";
	return output;
}

// 重载流输入运算符 >>
istream& operator>>(istream& input, Matrix& m)
{
	cout << "create matrix" << endl;
	input >> m.a; input.ignore();
	input >> m.b; input.ignore();
	input >> m.c; input.ignore();
	input >> m.d; input.ignore();
	return input;
}

Matrix::Matrix() {}

Matrix::Matrix(int aa, int bb, int cc, int dd) : a(aa), b(bb), c(cc), d(dd) {}

// 重载加法运算符 +
const Matrix& Matrix::operator+(Matrix& m)
{
	cout << "+" << endl;
	return Matrix(a + m.a, b + m.b, c + m.c, d + m.d);
}

// 重载减法运算符 -
const Matrix& Matrix::operator-(const Matrix& m)
{
	cout << "-" << endl;
	return Matrix(a - m.a, b - m.b, c - m.c, d - m.d);
}

// 重载乘法运算符 *
const Matrix& Matrix::operator*(const Matrix& m)
{
	cout << "*" << endl;
	return Matrix((a * m.a + b * m.c), (a * m.b + b * m.d),
		(c * m.a + d * m.c), (c * m.b + d * m.d));
}

// 重载乘法运算符 * （与整数相乘）
const Matrix& Matrix::operator*(int i)
{
	cout << "*" << endl;
	return Matrix(a * i, b * i, c * i, d * i);
}

// 重载赋值运算符 =
const Matrix& Matrix::operator=(const Matrix& m)
{
	cout << "=" << endl;
	a = m.a;
	b = m.b;
	c = m.c;
	d = m.d;
	return *this;
}

// 重载复合赋值运算符 +=
const Matrix& Matrix::operator+=(const Matrix& m)
{
	cout << "+=" << endl;
	a += m.a;
	b += m.b;
	c += m.c;
	d += m.d;
	return *this;
}

// 重载复合赋值运算符 -=
const Matrix& Matrix::operator-=(const Matrix& m)
{
	cout << "-=" << endl;
	a -= m.a;
	b -= m.b;
	c -= m.c;
	d -= m.d;
	return *this;
}

// 重载复合赋值运算符 *=
const Matrix& Matrix::operator*=(const Matrix& m)
{
	cout << "*=" << endl;
	int tempa = a; int tempb = b; int tempc = c; int tempd = d;
	a = tempa * m.a + tempb * m.c;
	b = tempa * m.b + tempb * m.d;
	c = tempc * m.a + tempd * m.c;
	d = tempc * m.b + tempd * m.d;
	return *this;
}

// 重载复合赋值运算符 *= （与整数相乘）
const Matrix& Matrix::operator*=(int i)
{
	cout << "*=" << endl;
	a *= i;
	b *= i;
	c *= i;
	d *= i;
	return *this;
}

// 重载相等运算符 ==
bool Matrix::operator==(const Matrix& m) const
{
	if ((a == m.a) && (b == m.b) && (c == m.c) && (d == m.d))
		return true;
	else
		return false;
}

// 重载不相等运算符 !=
bool Matrix::operator!=(const Matrix& m) const
{
	return !(*this == m);
}