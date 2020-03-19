#ifndef STACK_H_
#define STACK_H_

#include<string>
#include<vector>

using namespace std;

class Stack
{
public:
	bool push(const string&);
	bool pop(string &elem);
	bool peek(string &elem);
	bool empty() const { return _stack.empty(); }
	bool full() const { return _stack.size() == _stack.max_size(); }
	int size() const { return _stack.size(); }

	bool find(const string &elem) const;
	int count(const string &elem) const;

	private:
	vector<string> _stack;
};


class flobalWrapper {
public:
	static int tests_passed(){ return _tests_passed; }
	static int tests_run() { return _tests_run; }
	static int version_number() { return _version_number; }
	static string version_stamp() { return _version_stamp; }
	static string program_name() { return _program_name; }

	static void tests_passed(int nval) { _tests_passed=nval; }
	static void tests_run(int nval) {  _tests_run=nval; }
	static void version_number(int nval) { _version_number=nval; }
	static void version_stamp(const string& nstmp) {  _version_stamp=nstmp; }
	static void program_name(const string& npm) {  _program_name=npm; }


private:
	static string _program_name;
	static string _version_stamp;
	static int _version_number;
	static int _tests_run;
	static int _tests_passed;
};

#endif
