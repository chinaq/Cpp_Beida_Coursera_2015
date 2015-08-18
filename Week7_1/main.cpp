#include <iostream>
using namespace std;

// 在此处补充你的代码
template <class T>
class CArray3D{
	class CArray2D{
		class CArray1D{


			T * ts;
		public:
			CArray1D(int k){
				ts = new int[k];
			}
			T& operator[](int k){
				return ts[k];
			}
		};


		CArray1D** ca1Ds;
	public:
		CArray2D(int j, int k){
			ca1Ds = new CArray1D*[j];
			for (int index = 0; index < j; index++){
				CArray1D* ca1d = new CArray1D(k);
				ca1Ds[index] = ca1d;
			}
		}
		CArray1D & operator[](int j){
			return *ca1Ds[j];
		}
	};



	CArray2D** ca2Ds;
public:
	CArray3D(int i, int j, int k){
		ca2Ds = new CArray2D*[i];
		for (int index = 0; index < i; index++){
			CArray2D* ca2d = new CArray2D(j, k);
			ca2Ds[index] = ca2d;
		}
	}
	CArray2D & operator[](int i){
		return *ca2Ds[i];
	}

};
//结束代码

int main()
{
	CArray3D<int> a(3, 4, 5);
	int No = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 5; ++k)
				a[i][j][k] = No++;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 5; ++k)
				cout << a[i][j][k] << ",";
	system("pause");
	return 0;
}





//样例输出
//
//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
//10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 
//20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 
//30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 
//40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 
//50, 51, 52, 53, 54, 55, 56, 57, 58, 59,