#include <iostream> 
#include <iterator> 
#include <set> 
using namespace std;
int main() {
	int a[] = { 8, 7, 8, 9, 6, 2, 1 };
	// �ڴ˴�������Ĵ���
	set<int> v(a, a+7);
	// �������
	ostream_iterator<int> o(cout, " ");
	copy(v.begin(), v.end(), o);
	system("pause");
	return 0;
}






//�������
//1 2 6 7 8 9