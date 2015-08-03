#include <iostream>
using namespace std;

class Base {
public:
	int k;
	Base(int n): k(n) { }
};

class Big  {
public:
	int v; Base b;
	// 在此处补充你的代码
	Big(int n): b(n) {							//“封闭类”Big，初始化时，必须初始化“成员对象”b, (week3)3.2_成员对象和封闭类.pdf
		v = n;
	}
};

int main()  {
	Big a1(5);									//调用“构造函数”
	Big a2 = a1;								//调用默认的“复制构造函数”，(week3)2.1_复制构造函数.pdf
	cout << a1.v << "," << a1.b.k << endl;
	cout << a2.v << "," << a2.b.k << endl;
	system("pause");
	return 0;
}






//输入
//无

//输出
//5, 5
//5, 5

