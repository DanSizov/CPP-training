#include <iostream>
#include <variant>
#include <algorithm>

namespace functions {

	template <typename T, typename U>
	class FuncClass {

	public:
		auto maxfunc(T& x, U& y);
		auto minfunc(T& x, U& y);
		void swapfunc(T& x, T& y);
		void oddFunc(int* x, int& size);
		void evenFunc(int* x, int& size);
		void oddOneFunc(int* x, int& size);
		void evenOneFunc(int* x, int& size);
	};

	template <typename T, typename U>
	auto FuncClass<T, U>::maxfunc(T& x, U& y) {

		return (x > y) ? x : y;
	}

	template <typename T, typename U>
	auto FuncClass<T, U>::minfunc(T& x, U& y) {

		return (x < y) ? x : y;
	}

	template <typename T, typename U>
	void FuncClass<T, U>::swapfunc(T& x, T& y) {

		x += y;
		y = x - y;
		x -= y;
		
	}

	template <typename T, typename U>
	void FuncClass<T, U>::oddFunc(int* x, int& size) {

		auto is_odd = [](int number) { return (number % 2); };
		if (std::all_of(x, x + size, is_odd)) {
			std::cout << "all elements are odd" << std::endl;
		}
		else {
			std::cout << "not all elements are odd" << std::endl;
		}
	}

	template <typename T, typename U>
	void FuncClass<T, U>::evenFunc(int* x, int& size) {

		auto is_even = [](int number) { return !(number % 2); };
		if (std::all_of(x, x + size, is_even)) {
			std::cout << "all elements are even" << std::endl;
		}
		else {
			std::cout << "not all elements are even" << std::endl;
		}
	}

	template <typename T, typename U>
	void FuncClass<T, U>::oddOneFunc(int* x, int& size) {

		auto is_one_odd = [](int number) { return (number % 2); };
		if (std::any_of(x, x + size, is_one_odd)) {
			std::cout << "at least 1 element is odd" << std::endl;
		}
		else {
			std::cout << "no odd elements" << std::endl;
		}
	}

	template<typename T, typename U>
	void FuncClass<T, U>::evenOneFunc(int* x, int& size) {

		auto is_one_even = [](int number) { return !(number % 2); };
		if (std::any_of(x, x + size, is_one_even)) {
			std::cout << "at least 1 element is even" << std::endl;
		}
		else {
			std::cout << "no even elements" << std::endl;
		}
	}

}
void main() {

	int x{ 5 };
	double q{ 1.1 };
	int y{ 1 };

	functions::FuncClass<int, double> myFuncClass;

	std::cout << myFuncClass.maxfunc(x, q) << std::endl;
	std::cout << myFuncClass.minfunc(x, q) << std::endl;
	myFuncClass.swapfunc(x, y);
	std::cout << x << " , " << y << std::endl;


	int oddArray[7]{ 1, 3, 5, 7, 9, 11, 13};
	int sizeOddArray{ sizeof(oddArray) / sizeof(oddArray[0]) };

	int evenArray[6]{ 2, 4, 6, 8, 10, 12 };
	int sizeEvenArray{ sizeof(evenArray) / sizeof(evenArray[0]) };

	int oneOddArray[3]{ 2, 2, 4 };
	int sizeOneOddArray{ sizeof(oneOddArray) / sizeof(oneOddArray[0]) };

	int oneEvenArray[4]{ 1, 1, 1, 1 };
	int sizeOneEvenArray{ sizeof(oneEvenArray) / sizeof(oneEvenArray[0]) };


	myFuncClass.oddFunc(oddArray, sizeOddArray);
	myFuncClass.evenFunc(evenArray, sizeEvenArray);
	myFuncClass.oddOneFunc(oneOddArray, sizeOneOddArray);
	myFuncClass.evenOneFunc(oneEvenArray, sizeOneEvenArray);
}