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

	//back返回最后一个元素
	elem = _stack.back();

	//pop_back删除最后一个元素
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
	//::是什么意思？全局变量？
	return ::find(_stack.begin(), end_it, elem) != end_it;
}

int Stack::count(const string &elem) const {
	return ::count(_stack.begin(), _stack.end(), elem);
}