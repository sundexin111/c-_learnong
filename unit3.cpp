#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

//3.1дһ����ȡ�ı��ļ��ĳ��򣬽��ļ���ÿ�����ִ���map.
//map��ker�ǵ��֣�value�Ǹõ������ı��г��ֵĴ������ٶ���һ����"�ų�����"��ɵ�set,
//��������a,an,or,the,and,but֮��ĵ��֣������ַ���map֮ǰ����ȷ���������ڲ����ų����۵���
//һ���ı��ļ���ȡ��ϣ�����ʾһ�ݵ����嵥����ʾ�����ֳ��ֵĴ�����

/*
void inititalize_exclusion_set(set<string>&);
void process_file(map<string, int>&, const set<string>&, ifstream&);
void user_query(const map<string, int>&);
void display_word_count(const map<string, int>&, ofstream&);


int main() {
	ifstream ifile("G:\\column.txt");
	ofstream ofile("G:\\column.map");
	if (!ifile || !ofile) {
		cerr << "unable to open file--bailing out!\n";
		return -1;
	}


	set<string> exclude_set;
	//exclude_set��������25����
	inititalize_exclusion_set(exclude_set);

	map<string, int> word_count;
	process_file(word_count, exclude_set, ifile);
	//user_query(word_count);
	display_word_count(word_count, ofile);

	system("pause");
	return 0;
}

void inititalize_exclusion_set(set<string> &exs) {
	static string _exclude_word_words[25] = {
		"the","and","but","that","then","are",
		"been","can","a","could","did","for","of",
		"had","have","him","his","her","its","is",
		"were","which","when","with","would"
	};

	exs.insert(_exclude_word_words, _exclude_word_words + 25);
}

//exclude_set����25���ʣ�ifile����һ�λ�
void process_file(map<string, int> &word_count, const set<string> &exclude_set, ifstream &ifile) {

	string word;
	//������һ��MooCat
	while (ifile >> word) {
		//�鿴MooCat�ڲ���exclude_set��
		//����ڣ���������������
		if (exclude_set.count(word))
			continue;
		//������ڣ��������У�˵��MooCat����ʼ�������1
		//��������������ð���Щ����ʾ����
		word_count[word]++;
	}
}

void user_query(const map<string, int> &word_map) {
	string search_word;
	cout << "please enter a word to search:q to quit";
	cin >> search_word;
	while (search_word.size() && search_word != "q") {
		map<string, int>::const_iterator it;
		if ((it = word_map.find(search_word)) != word_map.end())
			cout << "Found!" << it->first << "occurs" << it->second << "times.\n";
		else
			cout << search_word << "was not found in text.\n";
		cout << "\n Another search?(q to quit)";
		cin >> search_word;
	}
}

//word_map���ų�������дʣ�Ҫ���ļ��д�ӡ����
//word_map��Ŀ�Ķ�����
void display_word_count(const map<string, int> &word_map, ofstream &os) {
	//���� const_iterator���б���������const�������Ƕ�ȡmap�е�Ԫ�أ��������κ�д��
	//iter��һ��ָ�룬ָ��map�ĵ�һ��Ԫ��
	//end_it��һ��ָ�룬ָ��map�����һ��Ԫ��
	map<string, int>::const_iterator
		iter = word_map.begin(),
		end_it = word_map.end();
	//˵����Ϊ��
	while (iter != end_it) {
	//iter���ָ��ָ��������������Ϊmap<string,int>,firstָ����string,secondָ����int��������
		os << iter->first << "(" << iter->second << ")" << endl;
		++iter;
	}
	os << endl;
}
*/

//3.2��ȡ�ļ��ı����ݣ��������ݴ洢��vector;
//�������ַ������ȣ���vector��������;
//����һ��function object����sort,�������������������ַ���������һ���ַ�������С�ڵڶ���������true;
//��ӡ������vector
/*
class LessThan {
public:
	bool operator()(const string &s1, const string &s2) {
		return s1.size() < s2.size();
	}
};

int main() {
	ifstream ifile("G:\\MooCat.txt");
	ofstream ofile("G:\\MooCat.sort");
	if (!ifile || !ofile) {
		cerr << "unable to open file--bailing out!\n";
		return -1;
	}

	vector<string> text;
	string word;

	while (ifile >> word) {
		text.push_back(word);
	}

	sort(text.begin(),text.end(), LessThan());
	display_vector(text, ofile);

	system("pause");
	return 0;

}

template<typename elemType>
void display_vector(const vector<elemType> &vec, ostream &os = cout, int len = 8) {
	vector<elemType>::const_iterator
		iter = vec.begin(),
		end_it = vec.end();

	int elem_cnt = 1;
	while (iter != end_it)
		os << *iter++ << (!(elem_cnt++ %len) ? '\n' : ' ');
	os << endl;
}
*/

//3.3 ����һ��map,�Լ�ͥ����Ϊkey,value������С�������֡�
//���map����������������
//�����û�������������ѯ�������Դ�ӡmap�ڵ�ÿһ������

/*
typedef vector<string> vstring;

//��ȡ�ļ����������ݴ�ŵ�map��
void populate_map(ifstream&, map<string, vstring>&);
void display_map(const map<string, vstring>&, ostream&);
void query_map(const string&,const map<string, vstring>&);

int main() {
	map<string, vstring> families;
	ifstream nameFile("G://families.txt");
	if (!nameFile) {
		cerr << "Unable to find families.txt file.\n";
		return -1;
	}
	populate_map(nameFile, families);
	string family_name;
	while (1) {
		cout << "please enter a family name or q to quit";
		cin >> family_name;

		if (family_name == "q")
			break;
		query_map(family_name, families);
	}
	display_map(families, cout);

	system("pause");
	return 0;
}

//nameFile��text�ļ��еļ�ͥ�ͺ�������
//families��map�����м�ͥ�ͺ��ӵ�����
void populate_map(ifstream &nameFile, map<string, vstring> &families) {
	string textline;

	//getline()��׼���ṩ�ĺ��������ļ���ȡһ������
	//textline�Ƕ������������
	while (getline(nameFile, textline)) {
		string fam_name;
		vstring child;
		string::size_type
			pos = 0, prev_pos = 0,
			//�м���
			text_size = textline.size();

		//����find_first_not_of()��������: 
		//�������ַ������״γ��ֵĲ�ƥ��str�κ��ַ������ַ�����, ��index��ʼ����, ���ȫ��ƥ���򷵻�string::npos
		while ((pos = textline.find_first_of(' ', pos))
			!= string::npos) {
			//�������ַ������յ�

			string::size_type end_pos = pos - prev_pos;
			//����prev_pos��δ���ã�����˵��ֵΪ0������ô�����ĵ��־���
			//��ͥ���ϣ������������
			if (!prev_pos) 
				fam_name = textline.substr(prev_pos, end_pos);
			else child.push_back(textline.substr(prev_pos, end_pos));
			prev_pos = ++pos;
			}

			//�������һ�����ӵ�����
			if (prev_pos<text_size)
				child.push_back(textline.substr(prev_pos, pos - prev_pos));

			if (!families.count(fam_name))
				families[fam_name] = child;
			else cerr << "Oops!We already have a" << fam_name << "family in our map!\n";
	}
}

void display_map(const map<string, vstring> &families, ostream &os) {
	map<string, vstring>::const_iterator
		it = families.begin(),
		end_it = families.end();
	while (it != end_it) {
		os << "The" << it->first << "familily";
		if (it->second.empty())
			os << "has no children\n";
		else {
			//��ӡ��vector��С��������
			os << "has" << it->second.size() << "children:";
			vector<string>::const_iterator
				iter = it->second.begin(),
				end_iter = it->second.end();
			while (iter != end_iter) {
				os << *iter << " "; ++iter;
			}
			os << endl;
		}
		++it;
	}
}

void query_map(const string &family, const map<string, vstring> &families) {
	map<string, vstring>::const_iterator
		it = families.find(family);

	if (it == families.end()) {
		cout << "Sorry.The" << family << "is not currently entered.\n";
		return;
	}
	cout << "The" << family;
	if (!it->second.size())
		cout << "has no children\n";
	else {
		cout << "has" << it->second.size() << "children:";
		vector<string>::const_iterator
			iter = it->second.begin(),
			end_iter = it->second.end();
		while (iter != end_iter) {
			cout << *iter << " ";
			++iter;
		}
		cout << endl;
	}
}
*/

//3.4 ����istream_iterator�ӱ�׼�����豸��ȡһ����������
//����ostream_iterator��������д��ĳ���ļ���ÿ����ֵ���Կո�ָ�
//������ostream_iteator��ż��д����һ���ļ���ÿ����ֵ��������һ��