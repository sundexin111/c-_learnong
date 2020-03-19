#include<iostream>
#include<string>
#include<vector>
#include"Stack.h"
#include <algorithm>
#include<fstream>

using namespace std;


//4.1建立Stack函数，练习Stack的所有公开接口
/*
int main() {

	ifstream infile("G://Stack.txt");
	
	Stack st;
	string str;

	cout << "Please enter a series of strings.\n";
	while (infile >> str && !st.full())
		st.push(str);

	if (st.empty()) {
		cout << '\n' << "Oops: no strings were read -- bailing out\n ";
		system("pause");
		return 0;
	}

	st.peek(str);
	if (st.size() == 1 && str.empty()) {
		cout << '\n' << "Oops: no strings were read -- bailing out\n ";
		system("pause");
		return 0;
	}

	cout << '\n' << "Read in " << st.size() << " strings!\n"
		<< "The strings, in reverse order: \n";

	while (st.size())
		if (st.pop(str))
			cout << str << ' ';

	cout << '\n' << "There are now " << st.size()
		<< " elements in the stack!\n";
	while (cin >> str && !st.full())
		st.push(str);
	if (st.empty()) {
		cout << "\n" << "There is nothing to read\n";
		return 0;
	}

	st.peek(str);
	if (st.size() ==1 && str.empty()) {
		cout<< "\n" << "There is nothing to read\n";
		return 0;
	}

	cout << "\n" << "Read in" << st.size() << "strings!\n"
		<< "The strings,in reverse order:\n";

	while (st.size())
		if (st.pop(str))
			cout << str << ' ';

	cout << '\n' << "There are now" << st.size()
		<< "elements in the stah!\n";


	system("pause");
	return 0;

}
*/


//4.2扩展Stack功能，支持find()和count()两个函数。
//find()会查看某值是否存在而且返回true或false
//count()返回某字符串出现的次数
/*
int main() {

	ifstream infile("G://Stack.txt");

	Stack st;
	string str;

	cout << "Please enter a series of strings.\n";
	while (infile >> str && !st.full())
		st.push(str);

	if (st.empty()) {
		cout << '\n' << "Oops: no strings were read -- bailing out\n ";
		system("pause");
		return 0;
	}

	st.peek(str);
	if (st.size() == 1 && str.empty()) {
		cout << '\n' << "Oops: no strings were read -- bailing out\n ";
		system("pause");
		return 0;
	}

	cout << '\n' << "Read in " << st.size() << " strings!\n";
	infile.clear();

	cout << "What word to search for?";
	cin >> str;
	bool found = st.find(str);
	int count = found ? st.count(str) : 0;

	cout << str <<" "<< (found ? "is" : "isn't") << " in the stack.";
	if (found)
		cout << "It occurs " << count << " times\n";

	system("pause");
	return 0;
}
*/

//4.3考虑下列所定义的全局数据：
//string program_name,string version_stamp;
//int version_number,int tests_run,int tests_passed;
//编写一个数据包装这些数据的类.

//4.4用户记录（user profile）内含以下数据：登录记录，实际姓名，登入次数，猜过次数，猜对次数
//等级-包括初级、中级，高级，专家，以及猜对百分比
//写一个名为UserProfile的class,提供一下操作：输入、输出、相等测试，不等测试
//constructor必须能够处理默认的用户等级，默认的登录名称（"guest".）
//对于同样名 为guest的多个用户，如何保证每个guest有独有的登录会话，不和其他人混淆