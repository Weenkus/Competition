#include <iostream>
#include <string>
#include <stack>

using namespace std;

void turnInfixToPostfix(string input);
bool isOperand(char c);

int main() {
	int numberOfExpressions{ 0 };
	cin >> numberOfExpressions;

	for (int i{ 0 }; i < numberOfExpressions; i++) {
		string inputExpression;
		cin >> inputExpression;
		turnInfixToPostfix(inputExpression);
		cout << endl;
	}


	return 0;
}

void turnInfixToPostfix(string input) {
	stack<int> operands;
	int element{ 0 };

	for (const char& c : input) {
		if (isalpha(c))
			cout << c;

		if (c == '(')
			operands.push(c);

		if (c == ')') {
			while (operands.top() != '('){
				element = operands.top();
				operands.pop();
				cout << static_cast<char>(element);
			}
			if (operands.top() == '(')
				operands.pop();
		}

		if (isOperand(c)) 
				operands.push(c);
		
	}
}

bool isOperand(char c) {
	return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}