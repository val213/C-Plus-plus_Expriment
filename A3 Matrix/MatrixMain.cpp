#include<iostream>
#include<ostream>
#include<istream>
#include<iomanip>
#include"Matrix.h"
using namespace std;

int main()
{
	Matrix matrix1;  // ����������� matrix1
	Matrix matrix2;  // ����������� matrix2

	cout << "��ʼ����A��" << endl;
	cout << matrix1;  // ��ӡ����A

	cout << "�����µľ���B��" << endl;
	cin >> matrix2;  // ���������ж�ȡ����B��ֵ

	cout << "���Ǹղ�����ľ���B" << endl;
	cout << matrix2;  // ��ӡ����B

	cout << "A+B=" << endl;
	cout << (matrix1 + matrix2);  // ��ӡ����A��B�ĺ�

	cout << "A-B=" << endl;
	cout << (matrix1 - matrix2);  // ��ӡ����A��B�Ĳ�

	cout << "A*B=" << endl;
	cout << (matrix1 * matrix2);  // ��ӡ����A��B�ĳ˻�

	cout << endl;

	int i;
	cout << "����һ��������";
	cin >> i;  // ���������ж�ȡһ������

	cout << "A*i=" << endl;
	cout << (matrix1 * i);  // ��ӡ����A��������i�Ľ��

	cout << endl;

	cout << "A+=B" << endl;
	cout << (matrix1 += matrix2);  // ��ӡ����A���Ͼ���B��Ľ��

	cout << endl;

	cout << "A-=B" << endl;
	cout << (matrix1 -= matrix2);  // ��ӡ����A��ȥ����B��Ľ��

	cout << endl;

	cout << "A��B�Ƿ�һ�� �� " << endl;
	cout << (matrix1 == matrix2);  // ��ӡ����A��B�Ƿ���ȵĽ��

	cout << "\n\n";

	cout << "��A=B" << endl;
	cout << (matrix1 = matrix2);  // ������B��ֵ������A

	cout << endl;

	cout << "A��B�Ƿ�һ�£�" << endl;
	cout << (matrix1 != matrix2);  // ��ӡ����A��B�Ƿ���ȵĽ��

	return 0;
}