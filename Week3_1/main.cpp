#include <iostream>
using namespace std;
class A {
public:
	int val;

	//// �ڴ˴�������Ĵ���
	A(int n = 0) {					//����ת������, (week3)2.2_����ת�����캯��.pdf
		val = n;
	}

	A& GetObj() {
		return *this;				//�������������, (week2)2.2����, (week3)4.2_thisָ��.pdf
	}
	//// �������
};

int main()  {
	A a;
	cout << a.val << endl;
	a.GetObj() = 5;					//a.GetObj()��ȡ��a�Լ������ã� =5ʹ��������ת������������һ��Aʵ�������丶����a.GetObj(), Ҳͬʱ������a, (week3)2.2_����ת�����캯��.pdf
	cout << a.val << endl;
	system("pause");
}




//����
//��

//���
//0
//5

