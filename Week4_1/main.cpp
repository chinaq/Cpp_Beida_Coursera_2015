#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Complex {
private:
	double r, i;
public:
	void Print() {
		cout << r << "+" << i << "i" << endl;
	}
	//// �ڴ˴�������Ĵ���
	Complex operator=(string s){
		int pos = s.find("+", 0);
		string strR = s.substr(0, pos);
		this->r = atof(strR.c_str());
		string strI = s.substr(pos + 1, s.length() - pos - 2);
		this->i = atof(strI.c_str());
		return *this;
	}
	//// �������
};

int main() {
	Complex a;
	a = "3+4i"; a.Print();
	a = "5+6i"; a.Print();
	system("pause");
	return 0;
}






//����
//��
//
//���
//3 + 4i
//5 + 6i