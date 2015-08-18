#include <iostream>
#include <string>
using namespace std;

// �ڴ˴�������Ĵ���

template<class T>
class CMyistream_iterator{
private:
	T inputs[5];
	istream * _is;
	int now;
public:
	CMyistream_iterator(istream & is){
		_is = &is;
		*_is >> inputs[0];
		now = 0;
	}

	template<class T2>
	friend T2 & operator*(CMyistream_iterator<T2> & myIs);
	CMyistream_iterator & operator++(int k){
		now++;
		*_is >> inputs[now];
		return *this;
	}
};


template<class T>
T & operator *(CMyistream_iterator<T> & myIs){
	return myIs.inputs[myIs.now];
};

//�������

int main()
{
	CMyistream_iterator<int> inputInt(cin);
	int n1, n2, n3;
	n1 = *inputInt; //���� n1
	int tmp = *inputInt;
	cout << tmp << endl;
	inputInt++;
	n2 = *inputInt; //���� n2
	inputInt++;
	n3 = *inputInt; //���� n3
	cout << n1 << "," << n2 << "," << n3 << endl;
	CMyistream_iterator<string> inputStr(cin);
	string s1, s2;
	s1 = *inputStr;
	inputStr++;
	s2 = *inputStr;
	cout << s1 << "," << s2 << endl;
	system("pause");
	return 0;
}