#include <iostream>
using namespace std;

class Sample{
public:
	int v;
	Sample(int n) :v(n) { }

	//// �ڴ˴�������Ĵ���
	Sample(Sample& s){	         //���ƺ�����(week3)2.1_���ƹ��캯��.pdf
		v = s.v * 2;
	}
	////�������

};
int main() {
	Sample a(5);
	Sample b = a;
	cout << b.v;
	system("pause");
	return 0;
}







//����
//��

//���
//10


