#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �ڴ˴�������Ĵ���
class CMy_add{
private:
	int & _sum;
public:
	CMy_add(int & sum) :_sum(sum) {}
	void operator()(int e){
		int low3 = e & 0xffffff07;
		_sum += low3;
	}
};
// �������

int main(int argc, char* argv[]) {
	int v, my_sum = 0;
	vector<int> vec;
	cin >> v;
	while (v) {
		vec.push_back(v);
		cin >> v;
	}
	for_each(vec.begin(), vec.end(), CMy_add(my_sum));
	cout << my_sum << endl;
	system("pause");
	return 0;
}

//����
//����һ�����������ɵ�����a[0], a[1], a[2], ..., a[n - 1], �������ǵĶ����Ƶ�3λ֮�͡�
//
//����
//����a, ��0��ʾ���������
//
//���
//һ������, �����������Ԫ�صĶ����Ƶ�3λ֮�͡�
//
//��������
//1 3 9 7 3 6 20 15 18 17 4 8 18 0
//
//�������
//41