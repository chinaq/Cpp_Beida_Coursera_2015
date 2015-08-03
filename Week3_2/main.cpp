#include <iostream>
using namespace std;

class Sample{
public:
	int v;
	Sample(int n) :v(n) { }

	//// 在此处补充你的代码
	Sample(Sample& s){	         //复制函数，(week3)2.1_复制构造函数.pdf
		v = s.v * 2;
	}
	////补充结束

};
int main() {
	Sample a(5);
	Sample b = a;
	cout << b.v;
	system("pause");
	return 0;
}







//输入
//无

//输出
//10


