/*
Total count

You are given an array arr[] of positive integers and a threshold value k. For each element in the array, divide it into the minimum number of small integers such that each divided integer is less than or equal to k. Compute the total number of these integer across all elements of the array.

Examples:

Input: k = 3, arr[] = [5, 8, 10, 13]
Output: 14
Explanation: Each number can be expressed as sum of different numbers less than or equal to k as 5 (3 + 2), 8 (3 + 3 + 2), 10 (3 + 3 + 3 + 1), 13 (3 + 3 + 3 + 3 + 1). So, the sum of count of each element is (2+3+4+5)=14.

Input: k = 4, arr[] = [10, 2, 3, 4, 7]
Output: 8
Explanation: Each number can be expressed as sum of different numbers less than or equal to k as 10 (4 + 4 + 2), 2 (2), 3 (3), 4 (4) and 7 (4 + 3).So, the sum of count of each element is (3 + 1 + 1 + 1 + 2) = 8.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
1 ≤ k ≤ 105

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int totalCount(int k, vector<int>& arr) {      
    int cnt = 0;
    // Loop through each element in the array
    for(int i = 0; i < arr.size(); i++) {
        // For each element, calculate how many parts it can be divided into
        // Each part should be <= k
        cnt += (arr[i] / k);
        // If there is a remainder, count one extra part
        if(arr[i] % k != 0) {
            cnt++;
        }
    }
    return cnt;
    }
};

int main() {
        string ks;
        cout<<"Enter the value of K: ";
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        cout<<"Enter the values: ";
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.totalCount(k, arr);
        cout << res << endl;
    
    return 0;
}
