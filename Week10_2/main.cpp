#include <iostream>
using namespace std;

class Number {
public:
	int num;
	Number(int n) : num(n) {
	}
	// 在此处补充你的代码
	int & value(){
		return num;
	}
	Number & operator +(Number & num2){
		num += num2.num;
		return *this;
	}
	//补充结束
};

int main() {

	Number a(2);
	Number b = a;
	cout << a.value() << endl;
	cout << b.value() << endl;
	a.value() = 8;
	cout << a.value() << endl;
	a + b;
	cout << a.value() << endl;
	system("pause");
	return 0;
}




//样例输入
//不需要输入
//
//样例输出
//2
//2
//8
//10