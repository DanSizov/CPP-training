//#include <iostream>	
//#include <string>
//
//using namespace std;
//
//int first{};
//int second{};
//
//struct myStruct
//{
//	int num;
//	std::string str;
//};
//
//enum trafficLight
//{
//	red,
//	yellow,
//	green
//};
//
//int sumFunc()
//{
//	int sum{ first + second };
//	return sum;
//};
//
//int substractFunc()
//{
//	int substract{ first - second };
//	return substract;
//};
//
//int main() {
//	//struct myStruct struct1;
//
//	//struct1.num = 5;
//	//struct1.str = "this is string";
//
//	//std::string myStr = "str";
//
//	//cout << "struct1.num now is: " << struct1.num << endl;
//
//	//struct1.num = 10;
//	//cout << "and now struct1.num is: " << struct1.num << endl;
//
//	//int a(6);
//	//cout << "variable a: " << a << endl;
//	//int b{ 7 };
//	//cout << "b is: " << b << endl;
//	//int c = { 8 };
//	//cout << "c is: " << c << endl;
//	//int r{};
//	//cout << "but now r is: " << r << endl;
//
//	//trafficLight colorRed = red;
//	//trafficLight colorYellow = yellow;
//	//trafficLight colorGreen = green;
//
//	//cout << "red color: " << red << endl;
//	//cout << "yellow color: " << yellow << endl;
//	//cout << "green color: " << green << endl;
//
//	//cout << "colorRed: " << colorRed << endl;
//	//cout << "colorYellow: " << colorYellow << endl;
//	//cout << "colorGreen: " << colorGreen << endl;
//
//	//cout << "size of red color enum: " << sizeof(red) << endl;
//	//cout << "size of red color: " << sizeof(colorRed) << endl;
//
//	//cout << "size of enum trafficLight: " << sizeof(trafficLight) << endl;
//
//	//cout << "this is the output with different variables. " + std::to_string(c) + " <- it was the variable 'c' and now you see the variable 'green' from enum 'trafficLight' :" + std::to_string(green) << endl;
//
//	//cout << "enter the number ";
//
//	//int x{};
//
//	//cin >> x;
//
//	//int doubled{ x * 2 };
//	//int trippled{ x * 3 };
//
//	//cout << "doubled: " << doubled << endl;
//	//cout << "trippled: " << trippled << endl;
//
//	//cout << "enter the first numer: ";
//	//cin >> first;
//
//	//cout << "enter the second number: ";
//	//cin >> second;
//
//	//cout << std::to_string(first) + " + " + std::to_string(second) + " = " << std::to_string(sumFunc()) + "." << endl;
//	//cout << std::to_string(first) + " - " + std::to_string(second) + " = " << std::to_string(substractFunc()) + "." << endl;
//
//	//char ch{ 'a' };
//	//cout << "int value: " << static_cast<int>(ch);
//
//	//double zero{ 0.0 };
//	//cout << 12 / zero;
//
//	//int x{ 5 };
//	//{
//	//	int& ref{ x };
//	//	cout << "ref is: " << ref << endl;
//	//	ref += 1;
//	//	cout << "now ref is: " << ref << endl;
//	//}
//	//cout << "x is: " << x << endl;
//
//
//
//	//cout << "enter the size of an array: " << endl;
//	//int size{};
//	//cin >> size;
//
//	//int* arr = new int[size];
//
//	//for (int i = 0; i < size; i++) {
//	//	arr[i] = i;
//	//};
//
//	//for (int i = 0; i < size; i++) {
//	//	cout << arr[i] << endl;
//	//};
//
//	////cout << "arr: " << arr << endl;
//	////cout << "*arr: " << *arr << endl;
//
//	//for (int i = 0; i < size; i++) {
//	//	*arr = arr[i];
//	//	cout << "*arr: " << *arr << endl;
//	//	cout << "arr: " << &arr[i] << endl;
//	//}
//
//	//delete[] arr;
//
//	cout << "enter a number: ";
//	int size{};
//	cin >> size;
//
//	int* arr = new int[size];
//	int* ptr = arr;
//
//	for (int i = 0; i < size; i++) {
//		arr[i] = i;
//	}
//
//	for (int i = 0; i < size; i++) {
//		cout << "arr[" + std::to_string(i) + "]" << " : " << arr[i] << endl;
//		cout << "address: " << &arr[i] << endl;
//	}
//
//	cout << "first address: " << arr << endl;
//	ptr += 1;
//	cout << "second address: " << ptr << endl;
//
//	delete[] arr;
//
//	return EXIT_SUCCESS;
//}