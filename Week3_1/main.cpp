#include <iostream>
using namespace std;
class A {
public:
	int val;

	//// 在此处补充你的代码
	A(int n = 0) {					//类型转换函数, (week3)2.2_类型转换构造函数.pdf
		val = n;
	}

	A& GetObj() {
		return *this;				//返回自身的引用, (week2)2.2引用, (week3)4.2_this指针.pdf
	}
	//// 补充结束
};

int main()  {
	A a;
	cout << a.val << endl;
	a.GetObj() = 5;					//a.GetObj()获取到a自己的引用， =5使用了类型转换函数新生成一个A实例，将其付给了a.GetObj(), 也同时赋给了a, (week3)2.2_类型转换构造函数.pdf
	cout << a.val << endl;
	system("pause");
}




//输入
//无

//输出
//0
//5

