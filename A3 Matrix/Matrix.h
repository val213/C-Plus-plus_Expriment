#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
using std::ostream;
using std::istream;
using namespace std;

class Matrix
{
	friend ostream& operator<<(ostream&, const Matrix&); // ��Ԫ��������������
	friend istream& operator>>(istream&, Matrix&);       // ��Ԫ���������������

public:
	Matrix();                                           // Ĭ�Ϲ��캯��
	Matrix(int, int, int, int);                         // ���ι��캯��

	const Matrix& operator+(Matrix&);                    // �ӷ����������
	const Matrix& operator-(const Matrix&);              // �������������
	const Matrix& operator*(const Matrix&);              // �˷����������
	const Matrix& operator*(int);                        // �˷���������أ���������ˣ�
	const Matrix& operator=(const Matrix&);              // ��ֵ���������
	const Matrix& operator+=(const Matrix&);             // ���ϼӷ���ֵ���������
	const Matrix& operator-=(const Matrix&);             // ���ϼ�����ֵ���������
	const Matrix& operator*=(const Matrix&);             // ���ϳ˷���ֵ���������
	const Matrix& operator*=(int);                       // ���ϳ˷���ֵ��������أ���������ˣ�
	bool operator==(const Matrix&) const;                // ������������
	bool operator!=(const Matrix&) const;                // ��������������

private:
	int a = 1;                                          // ����Ԫ�� a
	int b = 0;                                          // ����Ԫ�� b
	int c = 0;                                          // ����Ԫ�� c
	int d = 1;                                          // ����Ԫ�� d
};

#endif
