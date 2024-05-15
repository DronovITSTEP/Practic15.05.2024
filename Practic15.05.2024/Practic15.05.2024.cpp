#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
	Array<int> arr;
	arr[2] = 8;
	cout << arr[2];
	int* num = new int;
	int* arNum = new int[5] {3, 6, 6};
	*num = 4;
	arr.InsertAt(3, arNum);
}
