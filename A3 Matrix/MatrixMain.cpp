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
	cout << "初始矩阵A：" << endl;
	cout << matrix1;
	cout<<"输入新的矩阵B：" << endl;
	cin>>matrix2;
	cout << "这是刚才输入的矩阵B" << endl;
	cout << matrix2;

	cout << "A+B=" << endl;
	cout<<(matrix1 + matrix2);
	cout << "A-B=" << endl;
	cout << (matrix1 - matrix2);
	cout << "A*B=" << endl;
	cout << (matrix1 * matrix2);
	cout << endl;

	int i;
	cout << "输入一个整数：";
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
	cout <<"A、B是否一致 ？ "<<endl;
	cout<<(matrix1 == matrix2);
	cout << "\n\n";
	cout << "令A=B" << endl;
	cout<<(matrix1 = matrix2);
	cout << endl;
	cout << "A、B是否不一致？" << endl;
	cout << (matrix1 != matrix2);

}