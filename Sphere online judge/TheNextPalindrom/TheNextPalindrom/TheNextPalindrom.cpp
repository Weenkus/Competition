#include <iostream>
#include <string>
#include <stack>

using namespace std;

void findNearestGreatestPalindrom(string inputString);
bool isPalindrom(string inputString);

int main() {
	int numberOfPalindroms{ 0 };
	cin >> numberOfPalindroms;

	
	for (int i = 0; i < numberOfPalindroms; i++) {
		string inputString;
		cin >> inputString;
		findNearestGreatestPalindrom(inputString);
 	}
}

void findNearestGreatestPalindrom(string inputString) {
	int number = atoi(inputString.c_str());
	do {
		++number;
		// Increase the speed by prefiltering caeses when the first and the last chars are not equal
		string optimizeCheck = to_string(number);
		int strLen = optimizeCheck.length();
		if (optimizeCheck.at(0) != optimizeCheck.at(strLen-1))
			continue;
		if (strLen % 2 == 0 && optimizeCheck.at(strLen / 2) == optimizeCheck.at((strLen - 1) / 2))
			continue;
	} while (!isPalindrom(to_string(number)));
	cout << number << endl;
}

bool isPalindrom(string inputString) {
	stack<char> palStack;
	//int i;
	int stringLen = inputString.length();
	int mid;

	if (stringLen % 2 == 0)
		mid = (stringLen) / 2;
	else
		mid = (stringLen - 1) / 2;

	for (int i{ 0 }; i < mid; i++) {
		palStack.push(inputString.at(i));
	}

	for (int i = mid+1; i < stringLen; i++) {
		if (palStack.top() != inputString.at(i))
			return false;
		palStack.pop();
	}
	
	return true;

	/*for (const char& c : inputString) {
		if (i < static_cast<double>(stringLen) / 2) {
			palStack.push(c);
		}else if (stringLen % 2 != 0 && i == (stringLen + 1)/2) {
			;
		}else {
			if (palStack.top() != c)
				return false;
			palStack.pop();
		}
		++i;
	}*/
	return true;
}