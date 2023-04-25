#include <iostream>
#include <variant>
#include <algorithm>
#include <functional>
#include <numeric>

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
		auto sortIntStructFunc(T* a, T* b, std::function<T(const T&)>f);

		struct IntStruct {
			int a;
			int b;
		};

		struct DoubleStruct {
			double c;
			double d;
		};

		struct StringStruct {
			const char* e;
			const char* f;
		};


	};