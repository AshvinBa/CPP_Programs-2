/*
Max sum in the configuration

Given an integer array(0-based indexing) a of size n. Your task is to return the maximum value of the sum of i*a[i] for all 0<= i <=n-1, where a[i] is the element at index i in the array. The only operation allowed is to rotate(clockwise or counterclockwise) the array any number of times.

Example 1:
Input: n = 4, a[] = {8, 3, 1, 2}
Output: 29
Explanation: All the configurations possible by rotating the elements are:
3 1 2 8 here sum is 3*0+1*1+2*2+8*3 = 29
1 2 8 3 here sum is 1*0+2*1+8*2+3*3 = 27
2 8 3 1 here sum is 2*0+8*1+3*2+1*3 = 17
8 3 1 2 here sum is 8*0+3*1+1*2+2*3 = 11, so the maximum sum will be 29.

Example 2:
Input: n = 3, a[] = {1, 2, 3}
Output: 8
Explanation: All the configurations possible by rotating the elements are:
1 2 3 here sum is 1*0+2*1+3*2 = 8
3 1 2 here sum is 3*0+1*1+2*2 = 5
2 3 1 here sum is 2*0+3*1+1*2 = 5, so the maximum sum will be 8.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1<=n<=105
1<=a[]<=106
*/

#include <bits/stdc++.h>
using namespace std;

/*You are required to complete this method*/
class Solution {
  public:
  
    long long max_sum(int a[], int n) {
        
        long long temp=0;
        long long sum=0,ans=0;
        for(long long int i=0;i<n;i++)
        {
            temp+=a[i]*i;
            sum+=a[i];
        }
        ans=temp;
        for(int i=1;i<n;i++)
        {
            temp=temp-sum+(long long)a[i-1]*n;
            ans=max(ans,temp);
        }
        return ans;
    }
};

int main() {
    int T;
    cout<<"Enter the number of test cases: ";
    cin >> T;
    while (T--) {
        int N;
        cout<<"Enter the size: ";
        cin >> N;
        int A[N];
        cout<<"Enter the values: ";
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout<<"Answer: ";
        cout << ob.max_sum(A, N) << endl;
    }
}
