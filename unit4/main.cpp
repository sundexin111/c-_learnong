//4.5ʵ��һ��4*4��Matrix class �������ṩ���½ӿڣ�����ӷ�������˷�����ӡ����printf()
//���������+=���Լ�һ��֧���±������function call�����
#include<iostream>
#include"Matrix.h"


using namespace std;


int main() {
	//int a;
	Matrix m;
	//cout << a << endl;
	cout << m << endl;
	
	elemType ar[16] = {
		1.,0.,0.,0.,0.,1.,0.,0.,
		0.,0.,1.,0.,0.,0.,0.,1.
	};
	
	Matrix identity(ar);
	cout << identity << endl;
	
	Matrix m2(identity);
	m = identity;
	cout << m2 << endl;
	cout << m << endl;

	elemType ar2[16] = {
		1.3,0.4,2.6,8.2,6.2,1.7,1.3,8.3,
		4.2,7.4,2.7,1.9,6.3,8.1,5.6,6.6
	};

	Matrix m3(ar2); 
	cout << m3 << endl;
	Matrix m4 = m3 * identity;
	cout << m4 << endl;
	Matrix m5 = m3 + m4;
	cout << m5 << endl;
	m3 += m4;
	cout << m3 << endl;

	system("pause");
	return 0;

}