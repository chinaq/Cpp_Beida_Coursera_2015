#include <iostream>
using namespace std;

int main() {
	double dIn;
	cin >> dIn;

	cout.setf(ios::fixed);
	cout.precision(5);
	cout << dIn << endl;

	cout.unsetf(ios::fixed);
	cout.setf(ios::scientific);
	cout.precision(7);
	cout << dIn << endl;

	system("pause");
}



//描述//
//利用流操纵算子实现： 输入一个实数，先以非科学计数法输出，小数点后面保留5位有效数字；再以科学计数法输出，小数点后面保留7位有效数字。//
//注意：在不同系统、编译器上的输出格式略有不同，但保证在程序中采用默认格式设置一定能在OJ平台上得到正确结果。
//
//输入
//以非科学计数法表示的一个正实数，保证可以用double类型存储。
//
//输出
//第一行：以非科学计数法输出该实数，小数点后面保留5位有效数字；//
//第二行：以科学计数法输出该实数，小数点后面保留7位有效数字。
//
//样例输入
//12.34
//
//样例输出
//12.34000
//1.2340000e+01