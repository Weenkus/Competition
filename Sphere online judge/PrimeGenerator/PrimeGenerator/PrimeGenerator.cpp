#include <iostream>
#include <math.h>

void printPrimesFromTo(int from, int to);
bool isPrime(int number);

int main() {
	int primeNumbers{ 0 };
	std::cin >> primeNumbers;

	for (int i{ 0 }; i < primeNumbers; i++) {
		int to{ 0 }, from{ 0 };
		std::cin >> from >> to;
		printPrimesFromTo(from, to);
	}

	return 0;
}


void printPrimesFromTo(int from, int to) {
	for (int i = from; i <= to; i++) {
		if (isPrime(i))
			std::cout << i << std::endl;
	}
}

bool isPrime(int number) {
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0)
			return false;
	}
	if (number == 1)
		return false;
	return true;
}