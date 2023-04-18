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

	int size = ask::askFunc();
	int* array = new int[size];

	for (int i = 0; i < size; i++) {

		array[i] = i + 1;
	}

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {

			for (int q = 0; q < size; q++) {

				std::cout << array[i] << " , " << array[j] << " , " << array[q] << std::endl;

			}

		}
	}

	delete[] array;
	return EXIT_SUCCESS;
}