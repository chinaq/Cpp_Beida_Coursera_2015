#include<string>
#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<sstream>
#include<set>

using namespace std;


multiset<int> intSet;
set<int> intSetAll;

void Add(){
	int x;
	cin >> x;
	intSet.insert(x);
	intSetAll.insert(x);
	cout << intSet.count(x) << endl;
}

void Del(){
	int x;
	cin >> x;
	multiset<int>::iterator p; 

	int count = 0;
	while (true){
		p = intSet.find(x);
		if (p != intSet.end()){
			intSet.erase(p);
			count++;
		}
		else{
			break;
		}
	}
	cout << count << endl;

}



void Ask(){
	int x;
	cin >> x;
	int count = intSet.count(x);
	int countAll = intSetAll.count(x);
	cout << (countAll > 0 ? 1:0) <<" "<< count << endl;
}


int main(){
	int n;
	cin >> n;
	string cmd;
	for (int i = 0; i < n; i++){
		cin >> cmd;
		if (cmd == "add")
			Add();
		else if (cmd == "del"){
			Del();
		}
		else if (cmd == "ask"){
			Ask();
		}
	}

	//system("pause");
}






//����
//����һ���������������ظ�Ԫ�أ�����ʼΪ�ա����Ƕ������²�����
//add x ��x���뼯��
//del x �Ѽ�����������x��ȵ�Ԫ��ɾ��
//ask x �Լ�����Ԫ��x�����ѯ��
//��ÿ�ֲ���������Ҫ��������������
//add ��������󼯺���x�ĸ���
//del �������ǰ������x�ĸ���
//ask �����0��1��ʾx�Ƿ��������뼯�ϣ�0��ʾ�������룩���������ǰ������x�ĸ������м��ÿո�񿪡�

//����
//��һ����һ������n����ʾ��������0 <= n <= 100000��
//����n�������Description��������
//
//���
//��n�У�ÿ�а�Ҫ�������

//��������
//7
//add 1
//add 1
//ask 1
//ask 2
//del 2
//del 1
//ask 1
//
//�������
//1
//2
//1 2
//0 0
//0
//2
//1 0

//��ʾ
//Please use STL��s set and multiset to finish the task