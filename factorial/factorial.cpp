#include <iostream>

namespace ask {

	int askFunc() {

		std::cout << "enter a number: ";
		int number{};
		std::cin >> number;

		return number;
	}

	long factorial(int number) {
		if (number < 0)
			return 0;
		if (number == 0)
			return 1;
		else
			return number * factorial(number - 1);
	}
}
	int main() {

		int myNumber = { ask::askFunc() };
		int& ref = { myNumber };
		std::cout << ask::factorial(ref);

		return EXIT_SUCCESS;
	}