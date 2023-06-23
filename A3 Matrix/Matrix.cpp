#include<iostream>
#include<iomanip>
#include"Matrix.h"
using std::ostream;
using std::istream;
using namespace std;
ostream& operator << (ostream&output, const Matrix&m)
{
	cout << "print matrix" << endl;
	output << m.a << " " << m.b << "\n";
	output << m.c << " " << m.d << "\n";
	return output;
}
istream& operator >> (istream&input,  Matrix&m)
{
	cout << "creat matrix" << endl;
	input >> m.a; input.ignore();
	input >> m.b; input.ignore();
	input >> m.c; input.ignore();
	input >> m.d; input.ignore();
	return input;
}
Matrix::Matrix() {}
Matrix::Matrix(int aa, int bb, int cc, int dd):a(aa), b(bb), c(cc), d(dd){}
//重载加法运算符的参数数量取决于它是单目运算符还是双目运算符，以及它是实现为类的成员函数还是非成员函数。
const Matrix& Matrix::operator+( Matrix&m)
{
	cout << "+" << endl;
	return Matrix(a + m.a, b + m.b, c + m.c, d + m.d);
}
const Matrix& Matrix::operator-(const Matrix&m)
{
	cout << "-" << endl;
	return Matrix(a-m.a,b-m.b,c-m.c,d-m.d);
}
const Matrix& Matrix::operator*(const Matrix&m)
{
	cout << "*" << endl;
	return Matrix((a * m.a + b * m.c), (a * m.b + b * m.d),
		(c * m.a + d * m.c), (c * m.b + d * m.d));
}
const Matrix& Matrix::operator*(int i)
{
	cout << "*" << endl;
	return Matrix(a * i,b * i, c * i, d * i);
}
const Matrix& Matrix::operator=(const Matrix&m)
{
	cout << "=" << endl;
	a = m.a;
	b = m.b;
	c = m.c;
	d = m.d;
	return *this;
}
const Matrix& Matrix::operator+=(const Matrix&m)
{
	cout << "+=" << endl;
	a += m.a;
	b += m.b;
	c += m.c;
	d += m.d;
	return *this;
}
const Matrix& Matrix::operator-=(const Matrix&m)
{
	cout << "-=" << endl;
	a -= m.a;
	b -= m.b;
	c -= m.c;
	d -= m.d;
	return *this;
}
const Matrix& Matrix::operator*=(const Matrix&m)//
{
	cout << "*=" << endl;
	int tempa = a; int tempb = b; int tempc = c; int tempd = d;
	a = tempa * m.a + tempb * m.c;
	b = tempa * m.b + tempb * m.d;
	c = tempc * m.a + tempd * m.c;
	d = tempc * m.b + tempd * m.d;
	return *this;
}
const Matrix& Matrix::operator*=(int i)
{
	cout << "*=" << endl;
	a *= i; b *= i; c *= i; d *= i;
	return *this;
}
bool Matrix::operator ==(const Matrix& m)const
{
	
	if ((a == m.a) && (b == m.b) && (c == m.c) && (d == m.d))
		return true;
	else return false;
}
bool Matrix::operator !=(const Matrix&m)const
{
	
	return (!(*this == m));
}

