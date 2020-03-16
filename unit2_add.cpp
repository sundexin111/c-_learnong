#include<iostream>
#include<string>
#include<vector>
# include<algorithm>

using namespace std;


//2.3将2.2Pen数列求值拆分为两个函数，其中一个是inline，检验元素个数是否合理
//如果合理，而且尚未被计算，执行第二个函数，执行实际求职工作。
/*
void really_calc_elems(vector<int> &vec, int pos) {
	for (int ix = vec.size() + 1; ix <= pos; ix++) {
		vec.push_back(ix * (3 * ix - 1) / 2);
	}
}
inline bool calc_elems(vector<int> &vec, int pos) {
	if (pos <= 0 || pos > 64) {
		cerr << "对不起，无效位置！";
		return false;
	}
	if (vec.size() < pos)
		really_calc_elems(vec, pos);
	return true;
}


void display(vector<int> &vec, const string &title) {
	cout << '\n' << title << "\n";
	for (int ix = 0; ix < vec.size(); ix++) {
		cout << "vec[" << ix << "]=" << vec[ix] << endl;
	}
	cout << endl;
}

	int main() {
		vector<int> pent;
		int nem;
		const string title("Pentagonal Numeric Series");
		cout << "请输入一个数：";
		cin >> nem;
		cout << "前" << nem << "元素是：";
		really_calc_elems(pent, nem);
		display(pent, title);
		system("pause");
		return 0;
	}
*/

//2.4写一个函数，以局部静态的vector储存Pentagonal数列元素。此函数返回一个const指针，指向该vector
//如果vector的大小小于指定元素个数，就扩充vector的大小
//接下来实现第二个函数，接受一个位置值，返回该位置上的元素

/*
inline bool check_validity(int pos) {
	return(pos <= 0 || pos > 64 ? false : true);
 }

//储存这个vector
//这是一个指针函数，*属于数据类型
const vector<int>* save_elems(int pos) {

	//elems是用来存储元素的，为static类型的
	static vector<int> _elems;
	if(check_validity(pos) && (pos>_elems.size()))
		for (int ix = _elems.size() + 1; ix <= pos; ix++) {
			_elems.push_back(ix * (3 * ix - 1) / 2);
		}
	return &_elems;
}

bool pen_ele(int pos, int &elem) {
	if (!check_validity(pos)) {
		cout << "这是一个无效的位置" << endl;
		return false;
	}
	//这个指着指向向量
	const vector<int> *pent = save_elems(pos);
	elem = (*pent)[pos - 1];
	return true;
}

int main() {
	int elem;
	if (pen_ele(8, elem))
		cout << "element 8 is " << elem << "\n";
	if (pen_ele(18, elem))
		cout << "element 18 is " << elem << "\n";
	if (pen_ele(12, elem))
		cout << "element 12 is " << elem << "\n";
	if (pen_ele(88, elem))
		cout << "element 88 is " << elem << "\n";

	system("pause");
	return 0;
}
*/
//2.5实现一个重载的max()函数，使其接受以下参数：
//（a)两个整数 (b)两个浮点数 （c）两个字符串 (d)一个整数vector(e) 一个浮点数vector
//(f)一个字符串vector,(g)一个整数数组，以及一个表示数组大小的整数值
//（h）一个浮点数数组，以及一个表示数组大小的整数值，
//（i）一个字符串数组，以及一个表示数组大小的整数值

/*
int max(int &i1, int &i2) {
	return(i1 > i2 ? i1 : i2);
}

float max(float &d1, float &d2) {
	return(d1 > d2 ? d1 : d2);
}

string max(string &s1, string &s2) {
	return(s1 > s2 ? s1 : s2);
}

int max(const vector<int> &vec) {
	return *max_element(vec.begin(), vec.end());
}

float max(const vector<float> &vec) {
	return *max_element(vec.begin(), vec.end());
}

string max(const vector<string> &vec) {
	return *max_element(vec.begin(), vec.end());
}

int max(const int *parray, int size) {
	return *max_element(parray, parray + size);
}

float max(const float *parray, int size) {
	return *max_element(parray, parray + size);
}


string max(const string *parray, int size) {
	return *max_element(parray, parray + size);
}


int main() {
	string sarray[] = { "we","were","a","big","family" };
	vector<string> svec (sarray, sarray + 5);

	int iarray []= { 5,9,6,4,3,2,1 };
	vector<int> ivec(iarray, iarray + 7);

	float farray[] = { 2.0,6.0,9.5,6.5,2.6,8.4 };
	vector<float> fvec(farray, farray + 6);

	int imax = max(max(ivec), max(iarray, 7));
	float fmax = max(max(fvec), max(farray, 6));
	string smax = max(max(svec), max(sarray, 5));

	cout << "imax=" << imax << "\t" << "fmax=" << fmax << "\t" << "smax=" << smax << endl;

	system("pause");
	return 0;
}
*/

//2.6 将2.5以template函数完成

template<typename Type>
inline Type max(Type t1, Type t2) {
	return t1 > t2 ? t1 : t2;
}

template<typename elemType>
inline elemType max(const vector<elemType> &vec) {
	return *max_element(vec.begin(), vec.end());
}

template<typename arraryType>
inline arraryType max(const arraryType *parray, int size) {
	return *max_element(parray, parray + size);
}

int main() {
	string sarray[] = { "we","were","a","big","family" };
	vector<string> svec(sarray, sarray + 5);

	int iarray[] = { 5,9,6,4,3,2,1 };
	vector<int> ivec(iarray, iarray + 7);

	float farray[] = { 2.0,6.0,9.5,6.5,2.6,8.4 };
	vector<float> fvec(farray, farray + 6);

	int ivec_max = max(ivec);
	int iarray_max=	max(iarray, 7);
	float fvec_max = max(fvec) ;
	float farray_max=max(farray, 6);
	string svec_max = max(svec);
	string sarray_max=max(sarray, 5);

	cout << "ivec_max=" << ivec_max << "\t" << "iarray_max=" << iarray_max << "\t" << "fvec_max=" << fvec_max << endl;
	cout << "farray_max=" << farray_max <<"\t" << "svec_max =" << svec_max << "\t" << "sarray_max =" << sarray_max << endl;

	system("pause");
	return 0;
}