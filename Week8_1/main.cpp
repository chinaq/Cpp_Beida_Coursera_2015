#include <iostream> 
#include <iterator> 
#include <set> 
using namespace std;
int main() {
	int a[] = { 8, 7, 8, 9, 6, 2, 1 };
	// 在此处补充你的代码
	set<int> v(a, a+7);
	// 补充结束
	ostream_iterator<int> o(cout, " ");
	copy(v.begin(), v.end(), o);
	system("pause");
	return 0;
}






//样例输出
//1 2 6 7 8 9