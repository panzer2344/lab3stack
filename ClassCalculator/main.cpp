#include "TCalculator.h"

void main() {
	//TCalculator calc();
	string request;

	cout << "Print ur request: ";
	cin >> request;

	cout << "Answer: " << TCalculator(request).Calculate() << endl;
}