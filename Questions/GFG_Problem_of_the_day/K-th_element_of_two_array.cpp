/*

K-th element of two Arrays
Given two sorted arrays arr1 and arr2 and an element k. The task is to find the element that would be at the kth position of the combined sorted array.

Examples :
Input: k = 5, arr1[] = [2, 3, 6, 7, 9], arr2[] = [1, 4, 8, 10]
Output: 6
Explanation: The final combined sorted array would be - 1, 2, 3, 4, 6, 7, 8, 9, 10. The 5th element of this array is 6.

Input: k = 7, arr1[] = [100, 112, 256, 349, 770], arr2[] = [72, 86, 113, 119, 265, 445, 892]
Output: 256
Explanation: Combined sorted array is - 72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892. 7th element of this array is 256.

Expected Time Complexity: O(log(n) + log(m))
Expected Auxiliary Space: O(log (n))

Constraints:
1 <= k<= arr1.size()+arr2.size()
1 <= arr1.size(), arr2.size() <= 106
0 <= arr1[i], arr2[i] < 108

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        
        vector<int>ans;
        
        int n=arr1.size();
        int m=arr2.size();
        int size=n+m;
        for(int i=0;i<n;i++)
        {
            ans.push_back(arr1[i]);
        }
        for(int j=0;j<m;j++)
        {
            ans.push_back(arr2[j]);
        }
        sort(ans.begin(),ans.end());
        
        return ans[k-1];
    }
};

int main() {
    int t;
    cout<<"Enter the size: ";
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cout<<"Enter the Kth value: "<<endl;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;
        cout<<"Enter the values for 1: ";
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }
        
        cout<<"Enter the values for 2: ";
        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout<<"Answer of the Questions: ";
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}