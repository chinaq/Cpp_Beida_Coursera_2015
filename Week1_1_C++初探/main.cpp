#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

class Student
{
public:
	void Input()
	{
		cin.getline(name, 100, ',');
		cin >> age;
		a = getchar();
		cin.getline(nums, 100, ',');
		cin >> g1 >> a >> g2 >> a >> g3 >> a >> g4;
	}
	void average()
	{
		aver = (g1 + g2 + g3 + g4) / 4;
	}
	void Output()
	{
		cout << name << "," << age << "," << nums << "," << aver;
		cout << endl;
	}
private:
	char name[100], nums[100], a;
	unsigned int age;
	int g1, g2, g3, g4;
	int aver;
};
int main()
{
	Student stu;
	stu.Input();
	stu.average();
	stu.Output();

	system("pause");
	return 0;
}









//描述
//在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。
//（注：评测系统无法自动判断变量是否私有。我们会在结束之后统一对作业进行检查，请同学们严格按照题目要求完成，否则可能会影响作业成绩。）

//输入
//姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。
//其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。
//各部分内容之间均用单个英文逗号","隔开，无多余空格。

//输出
//一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。
//各部分内容之间均用单个英文逗号","隔开，无多余空格。



//样例输入
//Tom, 18, 7817, 80, 80, 90, 70

//样例输出
//Tom, 18, 7817, 80