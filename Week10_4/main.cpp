#include <iostream>
using namespace std;

// �ڴ˴�������Ĵ���
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

// �������

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




//����
//���г���ÿ�ζ���һ������N����NΪ0���˳����������N��N��ƽ����

//����
//K�������������һ�������⣬�������ݾ���Ϊ0��
//
//���
//K - 1�С���I�������I��������������ƽ����

//��������
//1 5 8 9 0
//
//�������
//1 1
//5 25
//8 64
//9 81