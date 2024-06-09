/*
Convert array into Zig-Zag fashion

Given an array arr of distinct elements of size n, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the below form: 

arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n]. 

Note: Modify the given arr[] only, If your transformation is correct, the output will be 1 else the output will be 0. 

Examples

Input: n = 7, arr[] = {4, 3, 7, 8, 6, 2, 1}
Output: 1
Explanation:  After modification the array will look like 3 < 7 > 4 < 8 > 2 < 6 > 1, the checker in the driver code will produce 1.

Input: n = 5, arr[] = {4, 7, 3, 8, 2}
Output: 1
Explanation: After modification the array will look like 4 < 7 > 3 < 8 > 2 hence output will be 1.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 106
0 <= arri <= 109

*/


#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


class Solution {
  public:
  
    void zigZag(int n, vector<int> &arr) {
        
        for(long long i=0; i<n-1; i++)
        {
            if(i%2==0)
            {
                if(arr[i] > arr[i+1])
                {
                    swap(arr[i+1] , arr[i]);
                }
            }
            else
            {
                if(arr[i+1] > arr[i])
                {
                    swap(arr[i+1] , arr[i]);
                }
            }
        }        
    }
};

bool isZigzag(int n, vector<int> &arr) {
    int f = 1;

    for (int i = 1; i < n; i++) {
        if (f) {
            if (arr[i - 1] > arr[i])
                return 0;
        } else {
            if (arr[i - 1] < arr[i])
                return 0;
        }
        f = f ^ 1;
    }
    return 1;
}

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        obj.zigZag(n, arr);
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == i % 2) {
                flag = 0;
            } else {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << "0\n";
        } else {
            bool check = 1;
            check = isZigzag(n, arr);
            if (check)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
}
















