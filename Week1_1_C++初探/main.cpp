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









//����
//��һ��ѧ����Ϣ��������У�Ҫ��ʵ��һ������ѧ�����࣬�������г�Ա������Ӧ����˽�еġ�
//��ע������ϵͳ�޷��Զ��жϱ����Ƿ�˽�С����ǻ��ڽ���֮��ͳһ����ҵ���м�飬��ͬѧ���ϸ�����ĿҪ����ɣ�������ܻ�Ӱ����ҵ�ɼ�����

//����
//���������䣬ѧ�ţ���һѧ��ƽ���ɼ����ڶ�ѧ��ƽ���ɼ�������ѧ��ƽ���ɼ�������ѧ��ƽ���ɼ���
//����������ѧ��Ϊ�ַ����������ո�Ͷ��ţ�����Ϊ���������ɼ�Ϊ�Ǹ�������
//����������֮����õ���Ӣ�Ķ���","�������޶���ո�

//���
//һ�У���˳����������������䣬ѧ�ţ�����ƽ���ɼ�������ȡ������
//����������֮����õ���Ӣ�Ķ���","�������޶���ո�



//��������
//Tom, 18, 7817, 80, 80, 90, 70

//�������
//Tom, 18, 7817, 80