#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2{
private:
	int line;
	int col;
	int* ints;
public:
	Array2(int line=3, int col=4){
		this->line = line;
		this->col = col;
		ints = new int[line*col]; //i * 4 + j;
	}
	int * operator [](int i){
		return ints + i * col;
	}
	int operator() (int i, int j){
		return ints[i*col + j];
	}

	//friend ostream & operator << (ostream & os, const Array2 & array2);
};


//ostream & operator<<(ostream & os, const int & i){
//	os << i;
//	return os;
//}


int main() {
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++){
			//char * ai = a[i];
			//ai[j] = i * 4 + j;
			a[i][j] = i * 4 + j;
		}
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b; b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}