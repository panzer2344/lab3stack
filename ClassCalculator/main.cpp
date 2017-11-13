#include "TCalculator.h"

void main() {
	//TCalculator calc();
	string request;

	while (1) {
		cout << "Print ur request: ";
		cin >> request;

		if (request == "exit") break;

		cout << "Answer: " << TCalculator(request).Calculate() << endl;
	}
}