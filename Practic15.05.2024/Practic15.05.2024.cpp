#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	/*Array<int> arr;
	arr.SetSize(5, 4);
	cout << arr.GetSize()<< endl;

	cout << arr.GetUpperBound() ;
	arr.Add(8);
	arr.Add(47);
	arr.Add(5);
	arr.Add(6);
	cout << arr.GetUpperBound() << endl;
	cout << arr;
	arr.Add(1);
	arr.Add(2);
	cout << arr.GetSize()<< endl;
	arr.FreeExtra();
	cout << arr.GetSize()<< endl;
	arr.SetAt(4, 60);
	cout << arr.GetAt(4);

	arr[4] = 78;
	cout << arr;
	int* num = new int[10] {1,2,3, 4, 5, 6, 7, 8, 9, 0};

	arr.InsertAt(2, num, 10);
	cout << arr.GetSize()<< endl;
	cout << arr;
	arr.RemoveAt(4, 4);
	cout << arr;
	cout << arr.GetData();
	Array<int> arr1;
	arr1.SetSize(3);
	
	arr1.InsertAt(0, new int[3] {101, 102, 103}, 3);
	cout << arr1;
	arr=arr1;
	cout << arr;*/

	Array<string> arr1;
	Array<int*> arr2;

	arr1.Add(nullptr);
	arr1.Add(0);
	arr1.Add("world");

	cout <<arr1;
}
