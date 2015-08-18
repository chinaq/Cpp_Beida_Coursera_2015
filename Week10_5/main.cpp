#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 在此处补充你的代码
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
// 补充结束

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

//描述
//输入一个正整数构成的数组a[0], a[1], a[2], ..., a[n - 1], 计算它们的二进制低3位之和。
//
//输入
//数组a, 以0表示输入结束。
//
//输出
//一个整数, 所输入数组各元素的二进制低3位之和。
//
//样例输入
//1 3 9 7 3 6 20 15 18 17 4 8 18 0
//
//样例输出
//41