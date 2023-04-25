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
		auto sortIntStructFunc(T* a, T* b);

		struct IntStruct {
			int a;
			int b;
		};

		IntStruct intStructArray[5];

		struct DoubleStruct {
			double c;
			double d;
		};

		struct StringStruct {
			const char* e;
			const char* f;
		};

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
	void FuncClass<T, U>::findLessFunc(int* x, int& q, int& size) {

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

		auto res = std::transform(a, b, a, f);
		for (auto i = a; i < b; i++) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
		return res;
	}

	template<typename T, typename U>
	auto FuncClass<T, U>::reduceFunc(T* a, T* b, std::function<T(T& accum, const T& v)>f, T accum0) {

		auto res = std::accumulate(a, b, accum0, f);
		std::cout << "sum of an array members: " << res << std::endl;
		return res;
	}

	template<typename T, typename U>
	auto FuncClass<T, U>::sortIntStructFunc(T* a, T* b) {

		auto pred = [](const T& a, const T& b) { return a.a < b.a; };
		std::sort(a, b, pred);
		for (auto i = a; i < b; i++) {
			std::cout << " a: " << i->a << ", b: " << i->b << std::endl;
		}
	}
}