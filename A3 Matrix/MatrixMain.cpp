#include<iostream>
#include<ostream>
#include<istream>
#include<iomanip>
#include"Matrix.h"
using namespace std;

int main()
{
	Matrix matrix1;  // 创建矩阵对象 matrix1
	Matrix matrix2;  // 创建矩阵对象 matrix2

	cout << "初始矩阵A：" << endl;
	cout << matrix1;  // 打印矩阵A

	cout << "输入新的矩阵B：" << endl;
	cin >> matrix2;  // 从输入流中读取矩阵B的值

	cout << "这是刚才输入的矩阵B" << endl;
	cout << matrix2;  // 打印矩阵B

	cout << "A+B=" << endl;
	cout << (matrix1 + matrix2);  // 打印矩阵A和B的和

	cout << "A-B=" << endl;
	cout << (matrix1 - matrix2);  // 打印矩阵A和B的差

	cout << "A*B=" << endl;
	cout << (matrix1 * matrix2);  // 打印矩阵A和B的乘积

	cout << endl;

	int i;
	cout << "输入一个整数：";
	cin >> i;  // 从输入流中读取一个整数

	cout << "A*i=" << endl;
	cout << (matrix1 * i);  // 打印矩阵A乘以整数i的结果

	cout << endl;

	cout << "A+=B" << endl;
	cout << (matrix1 += matrix2);  // 打印矩阵A加上矩阵B后的结果

	cout << endl;

	cout << "A-=B" << endl;
	cout << (matrix1 -= matrix2);  // 打印矩阵A减去矩阵B后的结果

	cout << endl;

	cout << "A、B是否一致 ？ " << endl;
	cout << (matrix1 == matrix2);  // 打印矩阵A和B是否相等的结果

	cout << "\n\n";

	cout << "令A=B" << endl;
	cout << (matrix1 = matrix2);  // 将矩阵B赋值给矩阵A

	cout << endl;

	cout << "A、B是否不一致？" << endl;
	cout << (matrix1 != matrix2);  // 打印矩阵A和B是否不相等的结果

	return 0;
}