/*
Segregate 0s and 1s
Given an array arr consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

Examples :
Input: arr[] = [0, 0, 1, 1, 0]
Output: [0, 0, 0, 1, 1]
Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 1, 1].

Input: arr[] = [1, 1, 1, 1]
Output: [1, 1, 1, 1]
Explanation: There are no 0s in the given array, so the modified array is [1, 1, 1, 1]

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 1
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        
        int ones=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
            {
                ones++;
            }
        }
        
        int zeros = n - ones;
        
        for(int i=0;i<zeros;i++)
        {
            arr[i]=0;
        }
        
        for(int i=zeros;i<n;i++)
        {
            arr[i]=1;
        }
    }
};

int main() {
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        cout<<"Enter the values: ";
        getline(cin, input);
        stringstream ss(input);
        int number;
        
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}