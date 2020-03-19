#include<iostream>
#include<string>
#include<vector>
#include"Stack.h"
#include <algorithm>

using namespace std;

bool Stack::push(const string &elem) {
	if (full())
		return false;
	_stack.push_back(elem);
	return true;
}

bool Stack::pop(string &elem) {
	if (empty())
		return false;

	//back�������һ��Ԫ��
	elem = _stack.back();

	//pop_backɾ�����һ��Ԫ��
	_stack.pop_back();
	return true;
}

bool Stack::peek(string &elem) {
	if (empty())
		return false;
	elem = _stack.back();
	return true;
}

bool Stack::find(const string &elem)const {
	vector<string>::const_iterator end_it = _stack.end();
	//::��ʲô��˼��ȫ�ֱ�����
	return ::find(_stack.begin(), end_it, elem) != end_it;
}

int Stack::count(const string &elem) const {
	return ::count(_stack.begin(), _stack.end(), elem);
}