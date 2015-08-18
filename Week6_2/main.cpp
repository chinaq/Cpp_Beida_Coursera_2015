#include <iostream>
using namespace std;

class A {
	// 在此处补充你的代码
public:
	virtual ~A() { cout << "destructor A" << endl; }
	//代码结束
};

class B :public A {
public:
	~B() { cout << "destructor B" << endl; }
};

int main() {
	A * pa;
	pa = new B;
	delete pa;
	system("pause");
	return 0;
}




//样例输出
//
//destructor B
//destructor A