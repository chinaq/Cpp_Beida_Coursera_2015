#include <iostream>
using namespace std;

class Base {
public:
	int k;
	Base(int n): k(n) { }
};

class Big  {
public:
	int v; Base b;
	// �ڴ˴�������Ĵ���
	Big(int n): b(n) {							//������ࡱBig����ʼ��ʱ�������ʼ������Ա����b, (week3)3.2_��Ա����ͷ����.pdf
		v = n;
	}
};

int main()  {
	Big a1(5);									//���á����캯����
	Big a2 = a1;								//����Ĭ�ϵġ����ƹ��캯������(week3)2.1_���ƹ��캯��.pdf
	cout << a1.v << "," << a1.b.k << endl;
	cout << a2.v << "," << a2.b.k << endl;
	system("pause");
	return 0;
}






//����
//��

//���
//5, 5
//5, 5

