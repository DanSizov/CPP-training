#include <iostream>

namespace ask {

	int askFunc() {

		std::cout << "enter a number: ";
		int number{};
		std::cin >> number;

		return number;
	}
}
	int main() {

		int myNumber = ask::askFunc();
		long result{ 1 };
		for (int i = 1; i <= myNumber; i++) {
			
			result *= i;
		}

		std::cout << "result of a factorial: " << result << std::endl;

		return EXIT_SUCCESS;
	}