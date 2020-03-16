#include<iostream>
#include<string>
#include<vector>

using namespace std;



//2.1 fibon_elem()������ʹmain()�������û���Ҫ��ȡ���λ�õ�ֵ��ʹ�û���������λ��ֵ
//֪���û�ϣ��ֹͣΪֹ

/*
//?Ϊʲô�����Ĳ���һ��Ҫ�õ�ַ
bool fibon_elem(int pos, int &elem) {
	if (pos <= 0 || pos > 1024) {
		elem = 0;
		return false;
	}
	//λ��ʹ��1��2ʱ������ֵ��1
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
		cout << "������λ�ã�";
		cin >> pos;

		if (fibon_elem(pos, elem)) {
			cout << "λ��" << pos << "��ֵ��:" << elem << endl;
		}

		cout << "���ʻ�������һ��ô��y/n��:";
		cin >> answer;
		if (answer != 'y' && answer != 'Y') {
			more = false;
		}

	}
		system("pause");
		return 0;
}
*/

//2.2 Pentagonal���й�ʽP��n��=n(3n-1)/2
//����һ����������������Ԫ�ش��뵽vector�У�Ԫ�ظ������û�ָ��
//�ڶ�����������������vectorԪ��һһ��ӡ�������˺����ĵڶ����������ַ�������ʾ���vector�����е�����
bool calc_elements(vector<int> &vec, int pos) {
	if (pos <= 0 || pos > 64) {
		cerr << "�Բ�����Чλ�ã�";
		return false;
	}
	//cout << vec.size() << endl;
	//��1����ΪsizeĬ����0������������е�һ������1
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
	cout << "������һ������";
	cin >> nem;
	cout << "ǰ" << nem << "Ԫ���ǣ�";
	if (calc_elements(pent,nem)) {
		display(pent,title);
	}
	system("pause");
	return 0;
}
