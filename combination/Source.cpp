#include <iostream>
#include <string>

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

		for (int j = 1; j < size; j++) {

			if (array[j] > array[i]) {

				std::cout << array[i] << " , " << array[j] << std::endl;
			}
		}
	}
	delete[] array;
	return EXIT_SUCCESS;
}