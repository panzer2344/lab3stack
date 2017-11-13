#pragma once
#include <string>
#include <math.h>
#include "../LabStack/stack.h"
#include <iostream>

using namespace std;

class TCalculator {
private:
	string postfix;
	string infix;
	TStack<char> stc;
	TStack<double> std;

public:
	TCalculator(string _infix = ""): stc(), std(), infix(_infix), postfix("") {}
	TCalculator(const TCalculator& tc): stc(tc.stc), std(tc.std), infix(tc.infix), postfix(tc.postfix) {}
	
	void setinfix(const string& str);
	string getinfix() const;
	string getpostfix() const;
	bool Check();
	void ToPostfix();
	double Calculate();
	int Priority(char symbol);
};
