#include <iostream>
using namespace std;

class A {
	// �ڴ˴�������Ĵ���
public:
	virtual ~A() { cout << "destructor A" << endl; }
	//�������
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




//�������
//
//destructor B
//destructor A