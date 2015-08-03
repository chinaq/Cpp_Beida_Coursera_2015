#include <iostream>
using namespace std;
class MyInt {
	int nVal;
public:
	MyInt(int n) { nVal = n; }
	int ReturnVal() { return nVal; }
	// 在此处补充你的代码
	MyInt & operator-(const int& op2){
		nVal = nVal - op2;
		return *this;
	}
};

int main() {
	MyInt objInt(10);
	objInt - 2 - 1 - 3;
	cout << objInt.ReturnVal();
	cout << ",";
	objInt - 2 - 1;
	cout << objInt.ReturnVal();
	system("pause");
	return 0;
}