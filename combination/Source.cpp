#include <iostream>
#include <string>

namespace ask {

	int askFunc() {

		std::cout << "enter a number: ";
		int number{};
		std::cin >> number;

		return number;
	}

	void combination(int* array, int size, int i, int j) {

		if (i >= size) {
			return;
		}

		if (j >= size) {
			combination(array, size, i + 1, i + 2);
			return;
		}

		std::cout << array[i] << " , " << array[j] << std::endl;
		combination(array, size, i, j + 1);
	}
}

int main() {

	int size = ask::askFunc();
	int* array = new int[size];

	for (int i = 0; i < size; i++) {

		array[i] = i + 1;
	}

	ask::combination(array, size, 0, 1);
	
	delete[] array;
	return EXIT_SUCCESS;
}