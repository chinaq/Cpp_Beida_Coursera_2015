#include<iostream>
#include<string>
#include<cstdio>
using namespace std;




class Command{
	int lifeElement;
	//Soldier soldiers[];
	string createOrder[];
};


class Soldier{
	string type;
	int number, life, attack;
};


int main(){
	int loopTimes;

	int m;
	int dragonHp, ninjaHp, icemanHp, lionHp, wolfHp;

	cin >> loopTimes;
	for (int i = 0; i < loopTimes; i++){
		cin >> m;
		cin >> dragonHp >> ninjaHp >> icemanHp >> lionHp >> wolfHp;
	}

	cout << m << "," << dragonHp << "," << ninjaHp << "," << icemanHp << "," << lionHp << "," << wolfHp;
	system("pause");
}








//����⣣4��ħ������֮һ����ս

//	 ����
//	 ħ������������Ǻ�ħ����˾�����������ħ����˾�������˾�֮�����������е����ɳ��С�
//	 ��˾���City 1��City 2��������City n����˾�
//	 ������˾�����������ʿ����ʿһ���� dragon ��ninja��iceman��lion��wolf ���֡�ÿ����ʿ���б�š�����ֵ�����������������ԡ�
//	 ˫������ʿ��Ŷ��Ǵ�1��ʼ���㡣�췽��������ĵ�n����ʿ����ž���n��ͬ����������������ĵ�n����ʿ�����Ҳ��n��
//	 ��ʿ�ڸս�����ʱ����һ������ֵ��
//	 ��ÿ�����㣬˫����˾��и���һ����ʿ������
//	 �췽˾�����iceman��lion��wolf��ninja��dragon��˳��ѭ��������ʿ��
//	 ����˾�����lion��dragon��ninja��iceman��wolf��˳��ѭ��������ʿ��
//	 ������ʿ��Ҫ����Ԫ��
//	 ����һ����ʼ����ֵΪm����ʿ��˾��е�����Ԫ��Ҫ����m����
//	 ���˾��е�����Ԫ����������ĳ����˳��Ӧ���������ʿ����ô˾�����ͼ������һ�������������ʿ�����������ˣ���˾�ֹͣ������ʿ��
//	 ����һ��ʱ�䣬��˫��˾��ĳ�ʼ����Ԫ��Ŀ��Ҫ���㽫��0��0�ֿ�ʼ��˫��˾�ֹͣ������ʿΪֹ�������¼���˳�������
//	 һ���������¼������Ӧ������������£�
//
//	 1) ��ʿ����
//	 ��������� 004 blue lion 5 born with strength 5, 2 lion in red headquarter
//	 ��ʾ��4���������Ϊ5����ħlion��ʿ������������ʱ����ֵΪ5����������ħ˾��ﹲ��2��lion��ʿ����Ϊ������������ǵ��ʵĸ�����ʽ��ע�⣬ÿ�����һ���µ���ʿ����Ҫ�����ʱ˾��ﹲ�ж��ٸ�������ʿ��
//
//	 2) ˾�ֹͣ������ʿ
//	 ��������� 010 red headquarter stops making warriors
//	 ��ʾ��10�������췽˾�ֹͣ������ʿ
//	 ����¼�ʱ��
//	 ���Ȱ�ʱ��˳�������
//	 ͬһʱ�䷢�����¼����������˾��ģ��������˾��ġ�

//	 ����
//	 ��һ����һ��������������������������
//	 ÿ��������ݹ����С�
//	 ��һ�У�һ������M���京��Ϊ�� ÿ��˾�һ��ʼ����M������Ԫ(1 <= M <= 10000)��
//	 �ڶ��У���������������� dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ�����Ƕ�����0С�ڵ���10000��

//	 ���
//	 ��ÿ��������ݣ�Ҫ�������0ʱ0�ֿ�ʼ����˫��˾���ֹͣ������ʿΪֹ�������¼���
//	 ��ÿ��������ݣ��������"Case:n" n�ǲ������ݵı�ţ���1��ʼ ��
//	 ��������ǡ����˳��͸�ʽ��������¼���ÿ���¼������¼�������ʱ�俪ͷ��ʱ����СʱΪ��λ������λ��

//	 ��������
//	 1
//	 20
//	 3 4 5 6 7

//	 �������
//   Case : 1
//   000 red iceman 1 born with strength 5, 1 iceman in red headquarter
//   000 blue lion 1 born with strength 6, 1 lion in blue headquarter
//   001 red lion 2 born with strength 6, 1 lion in red headquarter
//   001 blue dragon 2 born with strength 3, 1 dragon in blue headquarter
//   002 red wolf 3 born with strength 7, 1 wolf in red headquarter
//   002 blue ninja 3 born with strength 4, 1 ninja in blue headquarter
//   003 red headquarter stops making warriors
//   003 blue iceman 4 born with strength 5, 1 iceman in blue headquarter
//   004 blue headquarter stops making warriors
