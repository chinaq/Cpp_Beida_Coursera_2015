#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAX_NUM_LEN = 201;

class BigInt {
private:
	char num[MAX_NUM_LEN];
	//int len;

public:
	BigInt(){
		//len = 1;
		memset(num, 0, sizeof(num));
		num[0] = '0';
	}
	BigInt(const char* charsNum){
		memcpy(num, charsNum, strlen(charsNum) + 1);

	}
	friend bool operator == (const BigInt & oprand1, const BigInt & oprand2);
	friend bool operator < (const BigInt & oprand1, const BigInt & oprand2);
	friend BigInt & operator + (const BigInt & oprand1, const BigInt & oprand2);
	friend BigInt & operator - (const BigInt & oprand1, const BigInt & oprand2);
	friend BigInt & operator * (const BigInt & oprand1, const BigInt & oprand2);
	friend BigInt & operator / (const BigInt & oprand1, const BigInt & oprand2);
	friend BigInt & divideBy2(const BigInt & oprand1);
	friend istream & operator >>(istream & is, BigInt & bigInt);
	friend ostream & operator <<(ostream & os, const BigInt & bigInt);
};





bool operator == (const BigInt & operand1, const BigInt & operand2){
	bool isEqual = true;
	int len1 = strlen(operand1.num);
	int len2 = strlen(operand2.num);
	if (len1 == len2){
		for (int i = 0; i < len1; i++){
			if (operand1.num[i] != operand2.num[i]){
				isEqual = false;
				break;
			}
			isEqual = true;
		}
	}
	else{
		isEqual = false;
	}
	return isEqual;

}




bool operator < (const BigInt & operand1, const BigInt & operand2){
	int len1 = strlen(operand1.num);
	int len2 = strlen(operand2.num);

	if (len1 < len2){
		return true;
	}
	else if (len1 > len2){
		return false;
	}

	for (int i = 0; i < len1; i++){
		if (operand1.num[i] < operand2.num[i]){
			return true;
		}
		else if (operand1.num[i] > operand2.num[i]){
			return false;
		}
	}
	return false;

}






//让两个字符串一样长
char* SetToMaxLen(int maxLen, int originLen, const char* originChars){

	int d = maxLen - originLen;
	//char* newChars = new char[maxLen];
	char* newChars = new char[MAX_NUM_LEN];
	memset(newChars, '0', d);
	memcpy(newChars + d, originChars, originLen + 1);
	return newChars;
}




BigInt &  operator+(const BigInt & operand1, const BigInt & operand2){
	BigInt& result = *new BigInt;
	int len1 = strlen(operand1.num);
	int len2 = strlen(operand2.num);
	int maxLen = len1 > len2 ? len1 : len2;

	char* new1 = SetToMaxLen(maxLen, len1, operand1.num);
	char* new2 = SetToMaxLen(maxLen, len2, operand2.num);

	//逐位相加
	char carry = 0;
	for (int i = maxLen - 1; i >= 0; i--){
		char dif = new1[i] - '0' + new2[i] - '0' + carry;
		result.num[i] = (dif) % 10 + '0';
		if (dif >= 10) carry = 1;
		else carry = 0;
	}

	//最高位进位则加1
	if (carry > 0){
		char* tempChars = new char[MAX_NUM_LEN];
		memcpy(tempChars, result.num, MAX_NUM_LEN);
		memcpy(result.num + 1, tempChars, maxLen);
		delete tempChars;
		//memcpy(result.num + 1, result.num, maxLen);	
		result.num[0] = '1';
	}

	return result;
}




BigInt &  operator-(const BigInt & operand1, const BigInt & operand2){
	BigInt& result = *new BigInt;
	int len1 = strlen(operand1.num);
	int len2 = strlen(operand2.num);
	int maxLen = len1 > len2 ? len1 : len2;

	char* new1 = SetToMaxLen(maxLen, len1, operand1.num);
	char* new2 = SetToMaxLen(maxLen, len2, operand2.num);


	//比较1和2哪个大？
	bool isOpd2Big = false;
	if (len1 < len2){
		isOpd2Big = true;
	}
	else{
		for (int i = 0; i < maxLen; i++){
			if (new1[i] < new2[i]){
				isOpd2Big = true;
				break;
			}
			else if (new1[i] > new2[i]){
				isOpd2Big = false;
				break;
			}
		}
	}

	//如果2大，交换
	if (isOpd2Big){
		char* tempChar;
		tempChar = new1;
		new1 = new2;
		new2 = tempChar;
	}



	//计算差值
	char carry = 0;
	for (int i = maxLen - 1; i >= 0; i--){
		char dif = (new1[i] - '0' + 10) - (new2[i] - '0') - carry;
		result.num[i] = (dif) % 10 + '0';
		if (new1[i] < new2[i] + carry) carry = 1;
		else carry = 0;
	}

	//去掉开头多余的0
	int zeroIndex = 0;
	for (int i = 0; i < maxLen - 1; i++){
		if (result.num[i] != '0')
			break;
		zeroIndex++;
	}
	if (zeroIndex > 0){
		char* tempChars = new char[MAX_NUM_LEN];
		memcpy(tempChars, result.num, MAX_NUM_LEN);
		memcpy(result.num, tempChars + zeroIndex, maxLen - zeroIndex + 1);
		delete tempChars;
		//memcpy(result.num, result.num + zeroIndex, maxLen - zeroIndex + 1);
	}

	//如果2大,前面加-号
	if (isOpd2Big){
		char* tempChars = new char[MAX_NUM_LEN];
		memcpy(tempChars, result.num, MAX_NUM_LEN);
		memcpy(result.num + 1, tempChars, maxLen);
		delete tempChars;
		//memcpy(result.num + 1, result.num, maxLen);
		result.num[0] = '-';
	}

	return result;
}




BigInt &  operator*(const BigInt & operand1, const BigInt & operand2){
	if (operand1 == BigInt("0") || operand2 == BigInt("0")){
		return *new BigInt("0");
	}

	int len1 = strlen(operand1.num);
	int len2 = strlen(operand2.num);

	BigInt* bigInts[MAX_NUM_LEN];// = new BigInt[len2];
	int bigIntsLen = len2;


	//循环第二个乘数的每一位
	for (int i = len2 - 1; i >= 0; i--){
		BigInt* oneLineResult = new BigInt("0");
		char carry = 0;
		//循环第一个乘数的每一位
		for (int j = len1 - 1; j >= 0; j--){
			char byteMul = (operand1.num[j] - '0') * (operand2.num[i] - '0') + carry;
			oneLineResult->num[j] = byteMul % 10 + '0';
			if (byteMul >= 10)
				carry = byteMul / 10;
			else
				carry = 0;
		}
		//进位
		int lenAdd = 0;
		if (carry > 0){
			char* tempChars = new char[MAX_NUM_LEN];
			memcpy(tempChars, oneLineResult->num, MAX_NUM_LEN);
			memcpy(oneLineResult->num + 1, tempChars, len1);
			delete tempChars;
			//memcpy(oneLineResult->num + 1, oneLineResult->num, len1);
			oneLineResult->num[0] = carry + '0';
			//len1 = len1 + 1;
			lenAdd = 1;
		}


		oneLineResult->num[len1 + lenAdd] = '\0';
		//追加0000
		//int originalOneLineLen = strlen(oneLineResult.num);
		int oldLen = strlen(oneLineResult->num);
		int zeroLen = len2 - i - 1;
		int allLen = oldLen + zeroLen;
		memset(oneLineResult->num + oldLen, '0', zeroLen);
		//int newLen = strlen(oneLineResult->num);
		oneLineResult->num[allLen] = '\0';
		bigInts[i] = oneLineResult;
	}

	//所有的位上的乘数累加起来
	BigInt& result = *new BigInt;
	for (int i = 0; i < bigIntsLen; i++){
		result = result + *bigInts[i];
		delete bigInts[i];
	}


	//return result;
	return result;
}




BigInt & operator / (const BigInt & oprand1, const BigInt & oprand2){
	if (oprand1 == oprand2)
		return *new BigInt("1");
	else if (oprand1 < oprand2)
		return *new BigInt("0");
	else if (oprand2 == BigInt("2")){
		return divideBy2(oprand1);
	}
	else if (oprand2 == BigInt("1")){
		BigInt* bigInt = new BigInt;
		*bigInt = oprand1;
		return *bigInt;
	}

	BigInt* realResult;
	BigInt mulResult;

	BigInt lastMulNum;
	BigInt& mulNum = *new BigInt("1");
	BigInt bigInt2("2");
	//mulNum = new BigInt("1");
	while (true){
		lastMulNum = mulNum;
		//BigInt tempNum = mulNum;
		//mulNum = tempNum * bigInt2;
		mulNum = mulNum * bigInt2;
		mulResult = oprand2 * mulNum;
		if (mulResult == oprand1){
			realResult = &mulNum;
			return *realResult;
		}
		else if (oprand1 < mulResult){
			break;
		}
	}

	BigInt tooBig = mulNum;
	BigInt tooSmall = lastMulNum;
	BigInt dif;
	BigInt divided;
	while (true){
		//lastMulNum = mulNum;
		dif = tooBig - tooSmall;
		divided = divideBy2(dif);
		mulNum = tooSmall + divided;
		mulResult = oprand2 * mulNum;
		if (mulResult == oprand1){
			return mulNum;
		}
		else if (mulResult < oprand1)
		{
			tooSmall = mulNum;
			tooBig = tooBig;
		}
		else
		{
			tooSmall = tooSmall;
			tooBig = mulNum;
		}

		if (divided == BigInt("0")){
			return mulNum;
		}
	}

}



BigInt & divideBy2(const BigInt & oprand1){

	int len = strlen(oprand1.num);
	BigInt & result = *new BigInt;
	//计算差值
	char carry = 0;
	for (int i = 0; i < len; i++){
		char toDivide = oprand1.num[i] - '0' + carry;
		char oneResult = toDivide / 2;
		result.num[i] = oneResult + '0';
		if (toDivide % 2 > 0)
			carry = 10;
		else
			carry = 0;
	}
	result.num[len] = '\0';

	//去掉开头多余的0
	int zeroIndex = 0;
	for (int i = 0; i < len - 1; i++){
		if (result.num[i] != '0')
			break;
		zeroIndex++;
	}
	if (zeroIndex > 0){
		char* tempChars = new char[MAX_NUM_LEN];
		memcpy(tempChars, result.num, MAX_NUM_LEN);
		memcpy(result.num, tempChars + zeroIndex, len - zeroIndex + 1);
		delete tempChars;
		//memcpy(result.num, result.num + zeroIndex, len - zeroIndex + 1);
	}
	return result;
}



istream & operator >> (istream & is, BigInt & bigInt){
	is >> bigInt.num;
	return is;
}

ostream & operator << (ostream & os, const BigInt & bigInt){
	cout << bigInt.num;
	return os;
}



int main(){
	BigInt a;
	char op;
	BigInt b;
	BigInt result;

	cin >> a >> op >> b;

	if (op == '+'){
		result = a + b;
	}
	else if (op == '-')
		result = a - b;
	else if (op == '*')
		result = a * b;
	else if (op == '/')
		result = a / b;

	cout << result << endl;
	//system("pause");
}














//编程题＃4：大整数的加减乘除
//
//
//	 注意： 总时间限制 : 1000ms 内存限制 : 65536kB
//
//	 描述
//	 给出两个正整数以及四则运算操作符（ + -*/ ），求运算结果。
//
//	 输入
//	 第一行：正整数a，长度不超过100
//	 第二行：四则运算符o，o是“ + ”，“ - ”，“*”，“ / ”中的某一个
//	 第三行：正整数b，长度不超过100
//	 保证输入不含多余的空格或其它字符
//
//	 输出
//	 一行：表达式“a o b”的值。
//
//	 补充说明：
//	 1. 减法结果有可能为负数
//	 2. 除法结果向下取整
//	 3. 输出符合日常书写习惯，不能有多余的0、空格或其它字符
//
//	 样例输入
//	 9876543210
//	 +
//	 9876543210
//
//	 样例输出
//	 19753086420