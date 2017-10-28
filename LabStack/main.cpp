#include "stack.h"
#include <iostream>

using namespace std;

void main() {
	TStack<int> s;
	int exit = 1, num = 0;

	while (exit) {
		cin >> exit;
		switch (exit)
		{
		case 1:
			cin >> num;
			s.push(num);
			break;
		case 2: 
			if (s.isEmpty()) break;
			cout << s.pop() << endl;
			break;
		case 3:
			if (s.isEmpty()) break;
			cout << s.top() << endl;
			break;
		default:
			break;
		}
	}
}