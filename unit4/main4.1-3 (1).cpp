#include<iostream>
#include<string>
#include<vector>
#include"Stack.h"
#include <algorithm>
#include<fstream>

using namespace std;


//4.1����Stack��������ϰStack�����й����ӿ�
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


//4.2��չStack���ܣ�֧��find()��count()����������
//find()��鿴ĳֵ�Ƿ���ڶ��ҷ���true��false
//count()����ĳ�ַ������ֵĴ���
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

//4.3���������������ȫ�����ݣ�
//string program_name,string version_stamp;
//int version_number,int tests_run,int tests_passed;
//��дһ�����ݰ�װ��Щ���ݵ���.

//4.4�û���¼��user profile���ں��������ݣ���¼��¼��ʵ������������������¹��������¶Դ���
//�ȼ�-�����������м����߼���ר�ң��Լ��¶԰ٷֱ�
//дһ����ΪUserProfile��class,�ṩһ�²��������롢�������Ȳ��ԣ����Ȳ���
//constructor�����ܹ�����Ĭ�ϵ��û��ȼ���Ĭ�ϵĵ�¼���ƣ�"guest".��
//����ͬ���� Ϊguest�Ķ���û�����α�֤ÿ��guest�ж��еĵ�¼�Ự�����������˻���