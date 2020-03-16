#include<iostream>
#include<string>
#include<vector>

using namespace std;



//2.1 fibon_elem()函数，使main()主函数用户想要获取多个位置的值，使用户不断输入位置值
//知道用户希望停止为止

/*
//?为什么函数的参数一定要用地址
bool fibon_elem(int pos, int &elem) {
	if (pos <= 0 || pos > 1024) {
		elem = 0;
		return false;
	}
	//位置使是1和2时，返回值是1
	elem = 1;
	int n_2 = 1, n_1 = 1;
	for(int ix = 3; ix <= pos;ix++){
		elem = n_2 + n_1;
		n_1 = n_2; 
		n_2 = elem;
	}
	return true;
}
int main() {
	int pos, elem;
	char answer;
	bool more = true;

	while (more) {
		cout << "请输入位置：";
		cin >> pos;

		if (fibon_elem(pos, elem)) {
			cout << "位置" << pos << "的值是:" << elem << endl;
		}

		cout << "请问还想再算一次么（y/n）:";
		cin >> answer;
		if (answer != 'y' && answer != 'Y') {
			more = false;
		}

	}
		system("pause");
		return 0;
}
*/

//2.2 Pentagonal数列公式P（n）=n(3n-1)/2
//定义一个函数，将产生的元素传入到vector中，元素个数由用户指定
//第二个函数，将给定的vector元素一一打印出来，此函数的第二个参数是字符串，表示存放vector内数列的类型
bool calc_elements(vector<int> &vec, int pos) {
	if (pos <= 0 || pos > 64) {
		cerr << "对不起，无效位置！";
		return false;
	}
	//cout << vec.size() << endl;
	//加1是因为size默认是0，但是这个数列第一个数是1
	for (int ix = vec.size()+1 ; ix <= pos; ix++) {
		vec.push_back(ix * (3 * ix - 1) / 2);
	}
	return true;
}

void display(vector<int> &vec, const string &title) {
	cout << '\n' << title << "\n";
	for (int ix = 0; ix < vec.size(); ix++) {
		cout <<"vec["<<ix<<"]="<< vec[ix] << endl;
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
	if (calc_elements(pent,nem)) {
		display(pent,title);
	}
	system("pause");
	return 0;
}
