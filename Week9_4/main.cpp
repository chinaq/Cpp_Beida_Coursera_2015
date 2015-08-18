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



//copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。
string Copy(){
	int N, X, L;
	N = do_NXL();
	X = do_NXL();
	L = do_NXL();

	return strp[N - 1].substr(X, L);
}


//add S1 S2：判断S1，S2是否为0 - 99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串。
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



//insert S N X：在第N个字符串的第X个字符位置中插入S字符串。
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





//描述
//
//给定n个字符串（从1开始编号），每个字符串中的字符位置从0开始编号，长度为1 - 500，现有如下若干操作：
//copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。
//add S1 S2：判断S1，S2是否为0 - 99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串。
//find S N：在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
//rfind S N：在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
//insert S N X：在第N个字符串的第X个字符位置中插入S字符串。
//reset S N：将第N个字符串变为S。
//print N：打印输出第N个字符串。
//printall：打印输出所有字符串。
//over：结束操作。
//其中N，X，L可由find与rfind操作表达式构成，S，S1，S2可由copy与add操作表达式构成。

//输入
//第一行为一个整数n（n在1 - 20之间）
//接下来n行为n个字符串，字符串不包含空格及操作命令等。
//接下来若干行为一系列操作，直到over结束。
//
//输出
//根据操作提示输出对应字符串。

//样例输入
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
//样例输出
//Op29adfk48
//358
//329strjvc
//Op29adfk48
//35a8

//提示
//推荐使用string类中的相关操作函数。