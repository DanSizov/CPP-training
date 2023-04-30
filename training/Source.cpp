#include <iostream>
#include "Class.h"
#include "Class.cpp"

struct IntStructNew {
	int a;
	int b;
};

IntStructNew intStructNewArray[5];

struct DoubleStructNew {
	double c;
	double d;
};

DoubleStructNew doubleStructNewArray[5];

struct StringStructNew {
	const char* e;
};

StringStructNew stringStructNewArray[5];

struct StructAll {
	int i;
	double d;
	const char* e;
};

StructAll structAllArray[3];

template <typename T>
void sortIntStructFuncNew(T* a, T* b) {

	auto pred = [](const T& a, const T& b) { return a.a < b.a; };
	std::sort(a, b, pred);
	for (auto i = a; i < b; i++) {
		std::cout << " a: " << i->a << ", b: " << i->b << std::endl;
	}
}

template <typename T>
void sortDoubleStructFuncNew(T* a, T* b) {

	auto pred = [](const T& a, const T& b) { return a.c < b.c; };
	std::sort(a, b, pred);
	for (auto i = a; i < b; i++) {
		std::cout << " c: " << i->c << ", d: " << i->d << std::endl;
	}
}

template <typename T>
void sortStringStructFuncNew(T* a, T* b) {

	auto pred = [](const T& a, const T& b) { return a.e < b.e; };
	std::sort(a, b, pred);
	for (auto i = a; i < b; i++) {
		std::cout << " e: " << i->e << std::endl;
	}
}

template<typename T>
void sortFuncNew(T* a, T* b) {

	auto pred = [](const T& a, const T& b) { return a.e < b.e; };
	std::sort(a, b, pred);
	for (auto i = a; i < b; i++) {
		std::cout << " " << i->e << std::endl;
	}
}

int main() {

	int x{ 5 };
	double q{ 1.1 };
	int y{ 1 };
	int w{ 5 };
	functions::FuncClass<int, double> myFuncClass{};

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

	functions::FuncClass<functions::FuncClass<int, int>::IntStruct, functions::FuncClass<double, double>::DoubleStruct> myStructClass;
	
	intStructNewArray[0].a = { 10 };
	intStructNewArray[0].b = { 10 };
	intStructNewArray[1].a = { 0 };
	intStructNewArray[1].b = { 3 };
	intStructNewArray[2].a = { 9 };
	intStructNewArray[2].b = { 2 };
	intStructNewArray[3].a = { 2 };
	intStructNewArray[3].b = { 2 };
	intStructNewArray[4].a = { 99 };
	intStructNewArray[4].b = { 99 };

	int sizeintStructNewArray{ sizeof(intStructNewArray) / sizeof(intStructNewArray[0]) };
	sortIntStructFuncNew(intStructNewArray, intStructNewArray + sizeintStructNewArray);

	doubleStructNewArray[0].c = { 4.4 };
	doubleStructNewArray[0].d = { 4.3 };
	doubleStructNewArray[1].c = { 3.4 };
	doubleStructNewArray[1].d = { 5.4 };
	doubleStructNewArray[2].c = { 1.4 };
	doubleStructNewArray[2].d = { 3.9 };
	doubleStructNewArray[3].c = { 2.4 };
	doubleStructNewArray[3].d = { 5.5 };
	doubleStructNewArray[4].c = { 1.7 };
	doubleStructNewArray[4].d = { 0.9 };

	int sizedoubleStructNewArray{ sizeof(doubleStructNewArray) / sizeof(doubleStructNewArray[0]) };
	sortDoubleStructFuncNew(doubleStructNewArray, doubleStructNewArray + sizedoubleStructNewArray);

	stringStructNewArray[0].e = { "r" };
	stringStructNewArray[1].e = { "a" };
	stringStructNewArray[2].e = { "b" };
	stringStructNewArray[3].e = { "x" };
	stringStructNewArray[4].e = { "v" };

	int sizestringStructNewArray{ sizeof(stringStructNewArray) / sizeof(stringStructNewArray[0]) };

	std::cout << "Before sorting:" << std::endl;
	for (auto i = 0; i < sizestringStructNewArray; i++) {
		std::cout << " e: " << stringStructNewArray[i].e << std::endl;
	}
	std::cout << " after sorting: " << std::endl;
	sortStringStructFuncNew(stringStructNewArray, stringStructNewArray + sizestringStructNewArray);

	structAllArray[0].i = { 5 };
	structAllArray[0].d = { 1.1 };
	structAllArray[0].e = { "ab" };
	structAllArray[1].i = { 3 };
	structAllArray[1].d = { 2.2 };
	structAllArray[1].e = { "df" };
	structAllArray[2].i = { 1 };
	structAllArray[2].d = { 3.5 };
	structAllArray[2].e = { "cx" };

	int sizestructAllArray{ sizeof(structAllArray) / sizeof(structAllArray[0]) };

	std::cout << "Before sorting:" << std::endl;
	for (auto i = 0; i < sizestructAllArray; i++) {
		std::cout << " i: " << structAllArray[i].i << std::endl;
		std::cout << " d: " << structAllArray[i].d << std::endl;
		std::cout << " e: " << structAllArray[i].e << std::endl;
	}

	sortFuncNew(structAllArray, structAllArray + sizestructAllArray);

	return EXIT_SUCCESS;
}