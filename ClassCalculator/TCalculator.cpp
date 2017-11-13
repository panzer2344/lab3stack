#include "TCalculator.h"

void test() {
	string str = "3.1415pi";
	char* tmp;
	double res = strtod(&str[0], &tmp);
	int size = tmp - &str[0];

	cout << "res = " << res << endl;
	cout << "size = " << size << endl;
}

int TCalculator::Priority(char symbol) {
	switch (symbol)
	{
	case '^':
		return 3;
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '(':
		return 0;
	case ')':
		return 0;
	default:
		return -1;
		break;
	}
}

void TCalculator::setinfix(const string& str) {
	infix = str;
}

string TCalculator::getinfix() const {
	return infix;
}

string TCalculator::getpostfix() const {
	return postfix;
}

bool TCalculator::Check() {
	stc.clear();
	if (infix.length() < 0) return false;
	if (postfix.length() < 0) return false;

	for (int i = 0; i < infix.length(); i++) {
		if (infix[i] == '(') {
			if (!stc.isFull())stc.push(infix[i]);
		}
		if (infix[i] == ')') {
			if (stc.isEmpty()) return false;
			else stc.pop();
		}
	}
	if (!stc.isEmpty()) return false;
	return true;
}

void TCalculator::ToPostfix() {
	stc.clear();
	string buf = '(' + infix + ')';

	if (buf.length() < 0) throw -1;

	for (int i = 0; i < buf.length(); i++) {
		if (buf[i] == '(') {
			if (!stc.isFull()) stc.push(buf[i]);
		}
		if (buf[i] >= '0' && buf[i] <= '9' || buf[i] == '.') postfix += buf[i];
		if (buf[i] == ')') {
			char tmp;
			while ((tmp = stc.pop()) != '(') {
				postfix += tmp;
			}
		}
		if (buf[i] == '+' || buf[i] == '*' || buf[i] == '-' || buf[i] == '/' || buf[i] == '^') {
			postfix += " ";
			while (Priority(buf[i]) <= Priority(stc.top())) {
				postfix += stc.pop();
			}
			stc.push(buf[i]);
		}
	}
}
double TCalculator::Calculate() {
	if (!Check()) throw - 1;
	ToPostfix();

	std.clear();
	if (postfix.length() < 0) throw - 1;

	for (int i = 0; i < postfix.length(); i++) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
			double op2 = std.pop();
			double op1 = std.pop();

			switch (postfix[i]) {
			case '+':
				std.push(op1 + op2);
				break;
			case '-':
				std.push(op1 - op2);
				break;
			case '*':
				std.push(op1 * op2);
				break;
			case '/':
				std.push(op1 / op2);
				break;
			case '^':
				std.push(pow(op1, op2));
				break;
			default:
				break;
			}
		}
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.') {
			char* tmp;
			double res = strtod(&postfix[i], &tmp);
			i += tmp - &postfix[i] - 1;
			std.push(res);
		}
	}
	return std.pop();
}