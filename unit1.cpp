#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

//1.4�����������
//��1��Ҫ���û�ͬʱ�������֣�first name��������
//��2���޸���������ͬʱ��ӡ���Ϻ�����
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

//1.5ѯ���û�����������ȡ�û��������ݣ�����û�������Ч���ƣ���ӦһЩ��Ϣ
//ʵ�ַ�����1��ʹ��C-style�ַ���
//��2��ʹ��string
/*
//ʹ��string

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
		//����1
	default:
		cout << "Hello," << user_name << endl;
		break;
	}
	system("pause");
	return 0;
}
*/

//1.6�ӱ�׼�����豸�ж�ȡһ������������������������δ�ŵ�array��vector,Ȼ�������������������ȡ��ֵ�ܺ͡�
//�����ܺͼ�ƽ��ֵ�������׼����豸

/*
int main() {

	//ʹ��vector
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


	//ʹ��array
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

//1.7�����������ֲ����̣�дһ�����򣬴򿪸��ı��ļ���������ÿһ�����ֶ���ȡ��һ��vector<string>�����С�
//��������ʾ��cout,Ȼ��ʹ�÷����㷨sort(),��������������
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

//1.8��array�洢���ֲ�ͬ���ַ�����Ϣ�����Դ�������Ϊarray������ֵ�����Դ˷�ʽ��ʾ��ο��䡣
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