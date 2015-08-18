#include<iostream>
using namespace std;
class Number {
public:
	int num;
	Number(int n = 0) : num(n) {}
	Number & operator*(const Number & n2){
		int result = num * n2.num;
		return *new Number(result);
	}
	operator int()
	{
		return num;
	}
};


int main() {
	Number n1(10), n2(20);
	Number n3; n3 = n1*n2;
	cout << int(n3) << endl;
	system("pause");
	return 0;
}




//描述
//使代码输出结果为200.