#include <iostream>
#include <string>
//#include <cstring>  //vs是个sb，原本在dev c++是使用cstring库的
#include <cstdlib>
using namespace std;


// 在此处补充你的代码
class MyString :public string{
public:
	MyString() :string(){}
	//MyString(char * cs):string(cs){}	
	MyString(const char * cs) :string(cs){}
	MyString & operator +(MyString & op2){
		string s1 = *this;
		string s2 = op2;
		string s = s1 + s2;
		return *new MyString(s.c_str());
	}
	MyString & operator +(const char * cs2){
		string str1 = *this;
		string s = str1 + cs2;
		return *new MyString(s.c_str());
	}
	MyString & operator()(int s, int l){
		string str = substr(s, l);
		return *new MyString(str.c_str());
	}
};

MyString & operator+(const char * cs1, const MyString & myString){
	string str2 = myString;
	string s = cs1 + str2;
	return *new MyString(s.c_str());
}
//代码结束


int CompareString(const void * e1, const void * e2) {
	MyString * s1 = (MyString *)e1;
	MyString * s2 = (MyString *)e2;
	if (*s1 < *s2)     return -1;
	else if (*s1 == *s2) return 0;
	else if (*s1 > *s2) return 1;
}


int main() {
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big", "me", "about", "take" };
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	s4 = s3;    s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;    s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; ++i)
		cout << SArray[i] << endl;
	//输出s1从下标0开始长度为4的子串
	cout << s1(0, 4) << endl;
	//输出s1从下标为5开始长度为10的子串
	cout << s1(5, 10) << endl;
	system("pause");
	return 0;
}



//写一个MyString 类，使得程序输出如样例

//要求：MyString类必须是从C++的标准类string类派生而来。
//提示1：如果将程序中所有 "MyString" 用"string" 替换，那么题目的程序中除了最后两条语句编译无法通过外，
//其他语句都没有问题，而且输出和前面给的结果吻合。也就是说，MyString类对 string类的功能扩充只体现在最后两条语句上面。
//提示2 : string类有一个成员函数 string substr(int start, int length); 能够求从 start位置开始，长度为length的子串


//样例输入
//无
//
//样例输出
//1. abcd - efgh - abcd -
//2. abcd -
//3.
//4. abcd - efgh -
//5. efgh -
//6. c
//7. abcd -
//8. ijAl -
//9. ijAl - mnop
//10. qrst - abcd -
//11. abcd - qrst - abcd - uvw xyz
//about
//big
//me
//take
//abcd
//qrst - abcd -