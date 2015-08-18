#include <iostream> 
#include <iterator> 
#include <list> 
#include<cstdio>
#include<string>
#include<set>
#include<vector>
using namespace std;


class MyList{
public:
	int Id;
	list<int> lst;

	MyList(int id) {
		Id = id;
	}
};



void PrintList(const list<int> & lst) {
	int tmp = lst.size();
	if (tmp> 0) {
		list<int>::const_iterator i;
		i = lst.begin();
		for (i = lst.begin(); i != lst.end(); i++)
			cout << (*i) << " ";
	}
	cout << endl;
};


MyList & FindList(vector<MyList> & lst, int id) {
	int tmp = lst.size();
	if (tmp> 0) {
		vector<MyList>::iterator i;
		i = lst.begin();
		//		vector<MyList>::iterator iMin = lst.begin();
		//		vector<MyList>::iterator iMax = lst.end()-1;
		////		while(true){
		//			i = iMIn + (iMax - iMin)/2;
		//			if ((*i).Id == id)
		//				return (*i);
		//		}
		//		
		//		for (i = lst.begin(); i != lst.end(); i++)
		//			if ((*i).Id == id)
		//				return (*i);
		//		return (*i);
		return *(i + id - 1);
	}
};




int main(){
	int inLines;
	cin >> inLines;
	vector<MyList> vecs;
	for (int i = 0; i < inLines; i++){
		string cmd;
		cin >> cmd;
		if (cmd == "new"){
			int id;
			cin >> id;
			vecs.push_back(MyList(id));
		}
		else if (cmd == "add"){
			int id;
			cin >> id;
			MyList& list = FindList(vecs, id);

			int num;
			cin >> num;
			list.lst.push_back(num);
			list.lst.sort();

		}
		else if (cmd == "merge"){
			int id1;
			cin >> id1;
			MyList& list1 = FindList(vecs, id1);

			int id2;
			cin >> id2;
			MyList& list2 = FindList(vecs, id2);
			list1.lst.merge(list2.lst);

		}
		else if (cmd == "unique"){
			int id;
			cin >> id;
			MyList& list = FindList(vecs, id);
			list.lst.sort();
			list.lst.unique();
		}
		else if (cmd == "out"){
			int id;
			cin >> id;
			MyList& list = FindList(vecs, id);
			PrintList(list.lst);
		}
		//cout << "------did it------" << endl;
	}
	//system("pause");
	return 0;
}









//描述
//
//写一个程序完成以下命令：
//new id ——新建一个指定编号为id的序列(id<10000)
//add id num——向编号为id的序列加入整数num
//merge id1 id2——合并序列id1和id2中的数，并将id2清空
//unique id——去掉序列id中重复的元素
//out id ——从小到大输出编号为id的序列中的元素，以空格隔开

//输入
//第一行一个数n，表示有多少个命令(n＜＝２０００００)。以后n行每行一个命令。
//
//输出
//按题目要求输出。


//样例输入
//16
//new 1
//new 2
//add 1 1
//add 1 2
//add 1 3
//add 2 1
//add 2 2
//add 2 3
//add 2 4
//out 1
//out 2
//merge 1 2
//out 1
//out 2
//unique 1
//out 1
//
//样例输出
//1 2 3
//1 2 3 4
//1 1 2 2 3 3 4
//
//1 2 3 4