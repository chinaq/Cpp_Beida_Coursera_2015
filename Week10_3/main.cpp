#include <iostream>
using namespace std;

// 在此处补充你的代码
int sum(int* a, int n, int sqr(int n)){
	int result = 0;
	while (n--){
		result += sqr(a[n]);
	}
	return result;
}
// 补充结束

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



//描述
//请写出sum函数，使其可以计算输入数列的平方和。

//输入
//第一行是一个整数 t(t <= 10)，表示数据组数；
//每组输入数据包含两行，第一行是一个整数 n(n <= 100)，
//第二行是 n 个用空格分隔开的整数
//
//输出
//对每组输入数据，输出该组数据中 n 个整数的平方和

//样例输入
//2
//2
//4 3
//3
//0 1 2
//
//样例输出
//25
//5