#include<string>
#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<sstream>

using namespace std;


string* strp;
int n;


//bool IsInt(string & str){
//	if (str == "0")
//		return true;
//	int val;
//	val = atoi(str.c_str());
//	if (val != 0){
//		return true;
//	}
//	return false;
//}



bool IsInt(string str)
{
	for(int i = 0; i<str.length();i++)
	{
		if((str.at(i)>'9') || (str.at(i)<'0'))
		{
			return false;
		}
	}
	return true;
}




int do_NXL();
string do_S();


int Find(){
	string S;
	int N;

	S = do_S();
	N = do_NXL();

	int pos = strp[N - 1].find(S);
	if (pos == -1)
		pos = strp[N - 1].length();

	return pos;
}


int RFind(){
	string S;
	int N;

	S = do_S();
	N = do_NXL();

	int pos = strp[N - 1].rfind(S);
	if (pos == -1)
		pos = strp[N - 1].length();

	return pos;
}

int do_NXL(){
	int val;
	string cmd;
	cin >> cmd;
	if (cmd == "find"){
		val = Find();
	}
	else if (cmd == "rfind"){
		val = RFind();
	}
	else{
		val = atoi(cmd.c_str());
	}
	return val;
}



//copy N X L��ȡ����N���ַ�����X���ַ���ʼ�ĳ���ΪL���ַ�����
string Copy(){
	int N, X, L;
	N = do_NXL();
	X = do_NXL();
	L = do_NXL();

	return strp[N - 1].substr(X, L);
}


//add S1 S2���ж�S1��S2�Ƿ�Ϊ0 - 99999֮�����������������ת��Ϊ�������ӷ��������ǣ������ַ����ӷ������ص�ֵΪһ�ַ�����
string Add(){
	string S1;
	string S2;
	string result;

	S1 = do_S();
	S2 = do_S();

	if (IsInt(S1) && IsInt(S2)){
		int intS1 = atoi(S1.c_str());
		int intS2 = atoi(S2.c_str());
		if (intS1 >= 0 && intS1 <= 99999 && intS2 >= 0 && intS2 <= 99999){
			stringstream ss;
			ss << (intS1 + intS2);
			ss >> result;
	
			//cout << result;
			return result;
		}
	}

	result = S1 + S2;
	//cout << result;
	return result;
}



//insert S N X���ڵ�N���ַ����ĵ�X���ַ�λ���в���S�ַ�����
void Insert(){
	string S;
	int N, X;
	S = do_S();
	N = do_NXL();
	X = do_NXL();
	strp[N - 1].insert(X, S);
}



string do_S(){
	string cmd;
	string result;

	cin >> cmd;
	if (cmd == "copy"){
		result = Copy();
	}
	else if (cmd == "add"){
		result = Add();
	}
	else{
		result = cmd;
	}
	return result;
}


void Reset(){
	string S;
	int N;
	S = do_S();
	N = do_NXL();
	strp[N - 1] = S;
}



void Print(){
	int n;
	n = do_NXL();
	cout << strp[n - 1] << endl;
}


void PrintAll(){
	for (int i = 0; i < n; i++){
		cout << strp[i] << endl;
	}
}


int main(){
	cin >> n;
	strp = new string[n];
	for (int i = 0; i < n; i++){
		cin >> strp[i];
	}
	//for (int i = 0; i < n; i++){
	//	cout << strp[i] << endl;
	//}

	string cmd;
	while (true){
		cin >> cmd;
		if (cmd == "over")
			break;
		else if (cmd == "copy"){
			Copy();
		}
		else if (cmd == "add"){
			Add();
		}
		else if (cmd == "find"){
			Find();
		}
		else if (cmd == "rfind"){
			RFind();
		}
		else if (cmd == "insert"){
			Insert();
		}
		else if (cmd == "reset"){
			Reset();
		}
		else if (cmd == "print"){
			Print();
		}
		else if (cmd == "printall"){
			PrintAll();
		}
	}

	//system("pause");
}





//����
//
//����n���ַ�������1��ʼ��ţ���ÿ���ַ����е��ַ�λ�ô�0��ʼ��ţ�����Ϊ1 - 500�������������ɲ�����
//copy N X L��ȡ����N���ַ�����X���ַ���ʼ�ĳ���ΪL���ַ�����
//add S1 S2���ж�S1��S2�Ƿ�Ϊ0 - 99999֮�����������������ת��Ϊ�������ӷ��������ǣ������ַ����ӷ������ص�ֵΪһ�ַ�����
//find S N���ڵ�N���ַ����д���ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ��������ַ����ĳ��ȡ�
//rfind S N���ڵ�N���ַ����д��ҿ�ʼ��ѰS�ַ������������һ�γ��ֵ�λ�ã���û���ҵ��������ַ����ĳ��ȡ�
//insert S N X���ڵ�N���ַ����ĵ�X���ַ�λ���в���S�ַ�����
//reset S N������N���ַ�����ΪS��
//print N����ӡ�����N���ַ�����
//printall����ӡ��������ַ�����
//over������������
//����N��X��L����find��rfind�������ʽ���ɣ�S��S1��S2����copy��add�������ʽ���ɡ�

//����
//��һ��Ϊһ������n��n��1 - 20֮�䣩
//������n��Ϊn���ַ������ַ����������ո񼰲�������ȡ�
//������������Ϊһϵ�в�����ֱ��over������
//
//���
//���ݲ�����ʾ�����Ӧ�ַ�����

//��������
//3
//329strjvc
//Opadfk48
//Ifjoqwoqejr
//insert copy 1 find 2 1 2 2 2
//print 2
//reset add copy 1 find 3 1 3 copy 2 find 2 2 2 3
//print 3
//insert a 3 2
//printall
//over
//
//�������
//Op29adfk48
//358
//329strjvc
//Op29adfk48
//35a8

//��ʾ
//�Ƽ�ʹ��string���е���ز���������