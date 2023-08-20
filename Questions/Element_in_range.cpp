/*
Elements in the Range
Given an array arr[] containing positive elements. A and B are two numbers defining a range. The task is to check if the array contains all elements in the given range.

Example 1:
Input: N = 7, A = 2, B = 5
arr[] =  {1, 4, 5, 2, 7, 8, 3}
Output: Yes
Explanation: It has elements between
range 2-5 i.e 2,3,4,5

Example 2:
Input: N = 7, A = 2, B = 6
arr[] = {1, 4, 5, 2, 7, 8, 3}
Output: No
Explanation: Array does not contain 6.



*/

#include <iostream>
using namespace std;

bool range(int arr[], int n, int A, int B)
{
	int range = B - A;
	for (int i = 0; i < n; i++)
	{
		if ((abs(arr[i])) >= A && (abs(arr[i])) <= B)
		{
			int z = abs(arr[i]) - A;
			if (z < n && arr[z] > 0)
			{
				arr[z] *= -1;
			}
		}
	}
	int count = 0;
	for (int i = 0; i <= range && i < n; i++)
	{
		if (arr[i] > 0)
			return false;
		else
			count++;
	}
	if (count == range + 1)
		return true;

	return false;
}

int main()
{
	int arr[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
	int n = sizeof(arr) / sizeof(arr[0]);
	int A = 2;
	int B = 5;
	if (range(arr, n, A, B))
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}

