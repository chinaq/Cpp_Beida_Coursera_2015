#include <iostream>
using namespace std;

// 在此处补充你的代码
class CType{
private:
	int _n;
public:
	void setvalue(int n){
		_n = n;
	}
	int operator ++(int k){
		return _n;
	}
	friend ostream & operator <<(ostream & os, CType ct);
};

ostream & operator <<(ostream & os, CType ct){
	os << ct._n * ct._n;
	return os;
}

// 补充结束

int main(int argc, char* argv[]) {
	CType obj;
	int n;
	cin >> n;
	while (n) {
		obj.setvalue(n);
		cout << obj++ << " " << obj << endl;
		cin >> n;
	}
	system("pause");
	return 0;
}




//描述
//下列程序每次读入一个整数N，若N为0则退出，否则输出N和N的平方。

//输入
//K个整数。除最后一个数据外，其他数据均不为0。
//
//输出
//K - 1行。第I行输出第I个输入数和它的平方。

//样例输入
//1 5 8 9 0
//
//样例输出
//1 1
//5 25
//8 64
//9 81