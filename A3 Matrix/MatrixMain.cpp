#include<iostream>
#include<ostream>
#include<istream>
#include<iomanip>
#include"Matrix.h"
using namespace std;
int main()
{
	Matrix matrix1;
	Matrix matrix2;
	cout << "��ʼ����A��" << endl;
	cout << matrix1;
	cout<<"�����µľ���B��" << endl;
	cin>>matrix2;
	cout << "���Ǹղ�����ľ���B" << endl;
	cout << matrix2;

	cout << "A+B=" << endl;
	cout<<(matrix1 + matrix2);
	cout << "A-B=" << endl;
	cout << (matrix1 - matrix2);
	cout << "A*B=" << endl;
	cout << (matrix1 * matrix2);
	cout << endl;

	int i;
	cout << "����һ��������";
	cin >> i;
	cout << "A*i=" << endl;
	cout << (matrix1 * i);

	cout << endl;
	cout << "A+=B"<<endl;
	cout<<(matrix1 += matrix2);
	cout << endl;
	cout << "A-=B"<<endl;
	cout<<(matrix1 -= matrix2);
	cout << endl;
	cout <<"A��B�Ƿ�һ�� �� "<<endl;
	cout<<(matrix1 == matrix2);
	cout << "\n\n";
	cout << "��A=B" << endl;
	cout<<(matrix1 = matrix2);
	cout << endl;
	cout << "A��B�Ƿ�һ�£�" << endl;
	cout << (matrix1 != matrix2);

}