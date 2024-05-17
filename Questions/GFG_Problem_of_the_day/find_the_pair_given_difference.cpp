/*
Find Pair Given Difference

Given an array arr[] of size n and an integer x, return 1 if there exists a pair of elements in the array whose absolute difference is x, otherwise, return -1.

Example 1:
Input:
n = 6
x = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output:
1
Explanation:
Pair (2, 80) have absolute difference of 78.

Example 2:
Input:
n = 5
x = 45
arr[] = {90, 70, 20, 80, 50}
Output:
-1
Explanation:
There is no pair with absolute difference of 45.
Your Task:
You need not take input or print anything. Your task is to complete the function findPair() which takes integers n, x, and an array arr[] as input parameters and returns 1 if the required pair exists, return -1 otherwise.

Expected Time Complexity: O(n* Log(n)).
Expected Auxiliary Space: O(1).

Constraints:
1<=n<=106 
1<=arr[i]<=106 
0<=x<=105
*/

//{ Driver Code Starts
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


// } Driver Code Ends

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            
            if( x==0 && mp[arr[i]]>1) return 1;
            /*if any digit is repeat the return true suppose 1-1=0*/
        }
        
        if(x==0)return -1;
        
        for(int i=0;i<n;i++)
        {
            int sum=x+arr[i];
            if(mp.find(sum)!=mp.end())
            {
                return 1;
            }
        }
        return -1;
    }
};

/*
int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        
        int i=0,j=1;
        
        while(i<n && j<n)
        {
            if(abs(arr[j]-arr[i])==x && i!=j)
            {
                return 1;
            }
            else if(abs(arr[j]-arr[i])<x)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return -1;
    }
*/


/*
int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int i=0,j=i+1;
        
        while(i<n)
        {
            j=i+1;
            while(j<n)
            {
                if(abs(arr[i]-arr[j])==x)
                {
                    return 1;
                }
                else
                {
                    j++;
                }
            }
            i++;
        }
        return -1;
    }
*/

//{ Driver Code Starts.

int main() {
    int t;
    cout<<"Enter the number of test cases: ";
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}
