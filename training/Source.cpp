#include <iostream>
#include <variant>
#include <algorithm>
#include <functional>
#include <numeric>

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
		void calcFunc(int* x, int& size);
		void findLessFunc(int* x, int& q, int& size);
		auto mapFunc(T* a, T* b, std::function<T(const T&)>f);
		auto reduceFunc(T* a, T* b, std::function<T(T& accum, const T& v)>f, T accum0);
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

	template<typename T, typename U>
	void FuncClass<T, U>::calcFunc(int* x, int& size) {

		auto is_odd = [](int number) { return (number % 2); };
		auto is_even = [](int number) { return !(number % 2); };
		std::cout << "the amount of odd numbers: " << std::count_if(x, x + size, is_odd) << std::endl;
		std::cout << "the amount of even numbers: " << std::count_if(x, x + size, is_even) << std::endl;
	}

	template<typename T, typename U>
	void FuncClass<T, U>::findLessFunc(int* x,int& q, int& size) {

		auto isLess = [q](int number) { return (number < q); };
		auto res = std::find_if(x, x + size, isLess);
		if (res != x + size) {
			std::cout << "found! index: " << res - x << " , " << "value : " << *res << std::endl;
		}
		else {
			std::cout << "not found 404" << std::endl;
		}
	}

	template<typename T, typename U>
	auto FuncClass<T, U>::mapFunc(T* a, T* b, std::function<T(const T&)>f) {

		auto res = std::transform(a ,b, a, f);
		for (auto i = a; i < b; i++) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
		return res;
	}

	template<typename T, typename U>
	auto FuncClass<T, U>::reduceFunc(T* a, T* b, std::function<T(T& accum, const T& v)>f, T accum0) {

		auto res = std::transform_reduce(a, b, f);
		for (auto i = a; i < b; i++) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
		return res;
	}
}

int main() {

	int x{ 5 };
	double q{ 1.1 };
	int y{ 1 };
	int w{ 5 };
	functions::FuncClass<int, double> myFuncClass;

	std::cout << myFuncClass.maxfunc(x, q) << std::endl;
	std::cout << myFuncClass.minfunc(x, q) << std::endl;
	myFuncClass.swapfunc(x, y);
	std::cout << x << " , " << y << std::endl;


	int oddArray[7]{ 6, 6, 6, 3, 9, 11, 13};
	int sizeOddArray{ sizeof(oddArray) / sizeof(oddArray[0]) };

	int evenArray[6]{ 2, 4, 6, 8, 10, 12 };
	int sizeEvenArray{ sizeof(evenArray) / sizeof(evenArray[0]) };

	int oneOddArray[3]{ 2, 2, 4 };
	int sizeOneOddArray{ sizeof(oneOddArray) / sizeof(oneOddArray[0]) };

	int oneEvenArray[4]{ 1, 1, 1, 1 };
	int sizeOneEvenArray{ sizeof(oneEvenArray) / sizeof(oneEvenArray[0]) };

	int oddEvenArray[10]{ 1 ,1 ,3 ,5 ,5 ,6, 7, 8 ,9, 10 };
	int sizeOddEvenArray{ sizeof(oddEvenArray) / sizeof(oddEvenArray[0]) };

	int mapArray[4]{ 5 ,10 ,15 ,20 };

	int reduceArray[5]{ 2,3,4,5,6 };
	
	myFuncClass.oddFunc(oddArray, sizeOddArray);
	myFuncClass.evenFunc(evenArray, sizeEvenArray);
	myFuncClass.oddOneFunc(oneOddArray, sizeOneOddArray);
	myFuncClass.evenOneFunc(oneEvenArray, sizeOneEvenArray);
	myFuncClass.calcFunc(oddEvenArray, sizeOddEvenArray);
	myFuncClass.findLessFunc(oddArray, w, sizeOddArray);

	myFuncClass.mapFunc(mapArray, std::end(mapArray), [](auto a) { return a * a; });
	myFuncClass.reduceFunc(reduceArray, std::end(reduceArray), [](auto acc, auto a) {return acc + a; }, 0);
	
	return EXIT_SUCCESS;
}