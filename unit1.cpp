#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

//1.4扩充程序内容
//（1）要求用户同时输入名字（first name）和姓氏
//（2）修改输出结果，同时打印姓氏和名字
/*
int main() {

	string first_name, last_name;
	cout << "Please enter your first name:";
	cin >> first_name;
	cout << "Please enter your last name:";
	cin >> last_name;
	cout << "Hello," << first_name << last_name << "!"<<endl;

	system("pause");
	return 0;
}
*/

//1.5询问用户姓名，并读取用户输入内容，如果用户输入有效名称，响应一些信息
//实现方法（1）使用C-style字符串
//（2）使用string
/*
//使用string

int main() {
	string user_name;
	cout << "Please input the user_name:";
	cin >> user_name;

	switch (user_name.size())
	{
	case 0:
		cout << "The size of name can not be 0!"<<endl;
		break;
	case 1:
		cout << "please add another string!"<<endl;
		break;
		//超过1
	default:
		cout << "Hello," << user_name << endl;
		break;
	}
	system("pause");
	return 0;
}
*/

//1.6从标准输入设备中读取一串整数，并将读入的整数依次存放到array和vector,然后遍历两种容器，并求取数值总和。
//并将总和及平均值输出至标准输出设备

/*
int main() {

	//使用vector
	vector<int> ivec;
	int ival;
	int sum=0;
	cout << "Please input 5 nums:";
	while (cin >> ival) {
		ivec.push_back(ival);
	}
	for (int i = 0; i < ivec.size(); i++) {
		sum += ivec[i];
	}
	cout << "avec.size()=" << ivec.size() << endl;
	cout << "The total is:" << sum << endl;
	cout << "The average is:" << sum / ivec.size() << endl;


	//使用array
	const int array_size = 5;
	int array[array_size];
	int icin;
	int icnt=0;
	int sum = 0;
	cout << "please input 5 nums:";
	while (cin >> icin && icnt < array_size) {
		array[icnt++] = icin;
	}
	for (int i = 0; i < array_size; i++) {
		sum += array[i];
	}
	cout << "The total is:" << sum << endl;
	cout << "The average is:" << sum / array_size << endl;
	
	system("pause");
	return 0;
}
*/

//1.7输入两行文字并存盘，写一个程序，打开该文本文件，将其中每一个文字都读取到一个vector<string>对象中。
//将内容显示到cout,然后使用泛型算法sort(),对所有文字排序。
/*
int main() {
	ifstream in_file("G:\\text.txt");
	if (!in_file) {
		cerr << "unable to open input file!\n";
		system("pause");
		return -1;
	}
	ofstream out_file("G:\\sort.txt");
	if (!out_file) {
		cerr << "unable to open output file!\n";
		system("pause");
		return -2;
	}
	string word;
	vector<string> text;
	while (in_file >> word) {
		text.push_back(word);
	}
	int ix;
	cout << "unsortted text:\n";
	cout << text.size() << endl;
	for (int ix = 0; ix < text.size(); ix++) {
		cout << text[ix] << ' ';
	}
	cout << endl;

	sort(text.begin(), text.end());

	out_file << "sortted text:\n";
	for (int ix = 0; ix < text.size(); ix++) {
		out_file << text[ix] << ' ';
	}
	out_file << endl;

	system("pause");
	return 0;
}
*/

//1.8以array存储四种不同的字符串信息，并以答错次数作为array的索引值，并以此方式显示安慰语句。
/*
const char* msg_to_usr(int numm_tries)
{
	const int rsp_cnt = 5;
	static const char* usr_msgs[rsp_cnt] = {
		"Go on,make a guss.",
		"Oops,Nice guss but not quite it.",
		"Hum.Sorry.Wrong a second time",
		"Ah,this is harder than it looks,no?",
		"It must be getting pretty frustrating by now!"
	};
	if (num_tries < 0)
		num_tries = 0;
	else
		if (num_tries >= rsp_cnt)
			num_tries = rsp_cnt - 1;
	return usr_msgs[num_tries];
}
*/