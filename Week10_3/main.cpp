#include <iostream>
using namespace std;

// �ڴ˴�������Ĵ���
int sum(int* a, int n, int sqr(int n)){
	int result = 0;
	while (n--){
		result += sqr(a[n]);
	}
	return result;
}
// �������

int sqr(int n) {
	return n * n;
}

int main() {
	int t, n, a[0x100];
	cin >> t;
	for (int c = 0; c < t; ++c) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		cout << sum(a, n, sqr) << endl;
	}
	system("pause");
	return 0;
}



//����
//��д��sum������ʹ����Լ����������е�ƽ���͡�

//����
//��һ����һ������ t(t <= 10)����ʾ����������
//ÿ���������ݰ������У���һ����һ������ n(n <= 100)��
//�ڶ����� n ���ÿո�ָ���������
//
//���
//��ÿ���������ݣ�������������� n ��������ƽ����

//��������
//2
//2
//4 3
//3
//0 1 2
//
//�������
//25
//5