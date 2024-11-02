#include "MenuClass.h"
#include "ListSequence.h"
#include <iostream>
using namespace std;
int main()
{
	int arr[] = { 2,2,32,4,6,7,8,0 };
	ListSequence<int> test(arr, 7);
	test.Append(1234);
	test.Append(1234);
	test.GetSubsequence(2, 3);
	//int arr2[] = { 21,23,32,94,76,7,8,0 };
	//Sequence<int>* test2;
	//test2=	test.GetSubsequence(2,3);
	
	LinkedList <int> tt (arr, 5);
	tt.Append(123);
	tt.Append(123);
	tt.GetSubList(2, 5);
	//cout << "ASD";
	//Sequence<int>* test3 = test.Concat(test2);
	

}
