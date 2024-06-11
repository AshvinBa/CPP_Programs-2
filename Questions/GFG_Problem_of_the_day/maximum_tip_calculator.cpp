/*
Maximum Tip Calculator

In a restaurant, two waiters, A and B, receive n orders per day, earning tips as per arrays arr[i] and brr[i] respectively. If A takes the ith order, the tip is arr[i] rupees; if B takes it, the tip is brr[i] rupees.

To maximize total tips, they must distribute the orders such that:

A can handle at most x orders
B can handle at most y orders
Given that x + y ≥ n, all orders can be managed by either A or B. Return the maximum possible total tip after processing all the orders.

Examples

Input: n = 5, x = 3, y = 3, arr = {1, 2, 3, 4, 5}, brr = {5, 4, 3, 2, 1}
Output: 21
Explanation: Person A will serve the 3rd, 4th and 5th order while person B will serve the rest so the total tip from A = 3+4+5 & B = 5 + 4 i.e. 21. 
 

Input: n = 8, x = 4, y = 4, arr = {1, 4, 3, 2, 7, 5, 9, 6}, brr = {1, 2, 3, 6, 5, 4, 9, 8}
Output: 43
Explanation: Person A will serve 1st, 2nd, 5th and 6th order while Person B will serve the rest & the total tip will be 43.
 

Input: n = 7, x = 3, y = 4, arr[] = {8, 7, 15, 19, 16, 16, 18}, brr[] = {1, 7, 15, 11, 12, 31, 9}
Output: 110
Explanation: Person A will serve orders 8,19,18 while person B will serve 7,15, 12 & 31.
Expected Time Complexity: O(n*logn)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 105
1 ≤ x, y ≤ n
1 ≤ arr[i], brr[i] ≤ 109
*/


#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) 
    {
        vector<pair<int,int>>temp;
        
        for(int i=0;i<n;i++)
        {
            temp.push_back({abs(arr[i]-brr[i]),i});
        }
        sort(temp.begin(),temp.end());
        long long ans=0;
        
        for(int i=n-1;i>=0;i--)
        {
            int index = temp[i].second;
            
            if(arr[index] > brr[index])
            {
                if(x)
                {
                    ans+=arr[index];
                    x--;
                }
                else
                {
                    ans+=brr[index];
                    y--;
                }
            }
            else
            {
                if(y)
                {
                    ans+=brr[index];
                    y--;
                }
                else
                {
                    ans+=arr[index];
                    x--;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cout<<"Enter the test cases: ";
    scanf("%d ", &t);
    while (t--) {

        int n;
        cout<<"Enter the values: ";
        scanf("%d", &n);

        int x;
        cout<<"Entre the value of X: ";
        scanf("%d", &x);

        int y;
        cout<<"Enter the value of Y: ";
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        cout<<"Answer: ";
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}



