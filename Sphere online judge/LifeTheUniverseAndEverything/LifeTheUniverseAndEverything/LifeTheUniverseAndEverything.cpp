#include <iostream>

int main() {
	int inputNumber{ 0 };
	std::cin >> inputNumber;

	while (inputNumber != 42) {
		std::cout << inputNumber << std::endl;
		std::cin >> inputNumber;
	}

	return 0;
}