#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

//3.1写一个读取文本文件的程序，将文件的每个单字存入map.
//map的ker是单字，value是该单字在文本中出现的次数。再定义一份由"排除字眼"组成的set,
//包含诸如a,an,or,the,and,but之类的单字，将单字放入map之前，先确定该字眼在不在排除字眼当中
//一旦文本文件读取完毕，请显示一份单字清单，显示各单字出现的次数。

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
	//exclude_set中有了这25个词
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

//exclude_set中有25个词，ifile中有一段话
void process_file(map<string, int> &word_count, const set<string> &exclude_set, ifstream &ifile) {

	string word;
	//例，第一个MooCat
	while (ifile >> word) {
		//查看MooCat在不在exclude_set中
		//如果在，就跳出迭代部分
		if (exclude_set.count(word))
			continue;
		//如果不在，到达这行，说名MooCat这个词加数量加1
		//接下来就是如何让把这些词显示出来
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

//word_map是排除后的所有词，要在文件中打印出来
//word_map是目的端容器
void display_word_count(const map<string, int> &word_map, ofstream &os) {
	//这里 const_iterator进行遍历操作，const允许我们读取map中的元素，不允许任何写作
	//iter是一个指针，指向map的第一个元素
	//end_it是一个指针，指向map的最后一个元素
	map<string, int>::const_iterator
		iter = word_map.begin(),
		end_it = word_map.end();
	//说明不为空
	while (iter != end_it) {
	//iter这个指针指向两个东西，因为map<string,int>,first指的是string,second指的是int（次数）
		os << iter->first << "(" << iter->second << ")" << endl;
		++iter;
	}
	os << endl;
}
*/

//3.2读取文件文本内容，并将内容存储于vector;
//并根据字符串长度，对vector进行排序;
//定义一个function object传给sort,这个函数对象接受两个字符串，当地一个字符串长度小于第二个，返回true;
//打印排序后的vector
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

//3.3 定义一个map,以家庭姓氏为key,value是所有小孩的名字。
//令此map至少容纳六笔数据
//允许用户根据姓氏来查询，并得以打印map内的每一笔数据

/*
typedef vector<string> vstring;

//读取文件，并将内容存放到map中
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

//nameFile是text文件中的家庭和孩子名称
//families是map中所有家庭和孩子的名字
void populate_map(ifstream &nameFile, map<string, vstring> &families) {
	string textline;

	//getline()标准可提供的函数，从文件读取一行内容
	//textline是读入的文字行数
	while (getline(nameFile, textline)) {
		string fam_name;
		vstring child;
		string::size_type
			pos = 0, prev_pos = 0,
			//有几行
			text_size = textline.size();

		//函数find_first_not_of()功能如下: 
		//返回在字符串中首次出现的不匹配str任何字符的首字符索引, 从index开始搜索, 如果全部匹配则返回string::npos
		while ((pos = textline.find_first_of(' ', pos))
			!= string::npos) {
			//计算子字符串的终点

			string::size_type end_pos = pos - prev_pos;
			//倘若prev_pos并未设置（或者说其值为0），那么读到的单字就是
			//家庭姓氏，否则就是名字
			if (!prev_pos) 
				fam_name = textline.substr(prev_pos, end_pos);
			else child.push_back(textline.substr(prev_pos, end_pos));
			prev_pos = ++pos;
			}

			//处理最后一个孩子的名字
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
			//打印出vector内小孩的名字
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

//3.4 利用istream_iterator从标准输入设备读取一连串整数。
//利用ostream_iterator将其奇数写至某个文件，每个数值皆以空格分隔
//再利用ostream_iteator将偶数写道另一个文件，每个数值单独放在一行