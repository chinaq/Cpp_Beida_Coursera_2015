#include <iostream>
using namespace std;

class Number {
public:
	int num;
	Number(int n) : num(n) {
	}
	// �ڴ˴�������Ĵ���
	int & value(){
		return num;
	}
	Number & operator +(Number & num2){
		num += num2.num;
		return *this;
	}
	//�������
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




//��������
//����Ҫ����
//
//�������
//2
//2
//8
//10