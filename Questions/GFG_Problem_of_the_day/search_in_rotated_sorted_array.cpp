/*

Search in Rotated Sorted Array

Given a sorted (in ascending order) and rotated array arr of distinct elements which may be rotated at some point and given an element key, the task is to find the index of the given element key in the array arr. The whole array arr is given as the range to search.

Rotation shifts elements of the array by a certain number of positions, with elements that fall off one end reappearing at the other end.
Note:- 0-based indexing is followed & returns -1 if the key is not present.

Examples :

Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 10
Output: 5
Explanation: 10 is found at index 5.

Input: arr[] = [3, 5, 1, 2], key = 6
Output: -1
Explanation: There is no element that has value 6.

Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
1 ≤ key ≤ 105

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        
        int s=0;
        int e=arr.size()-1;
        int mid=(s+e)/2;
        
        while(s<=e)
        {
            mid=(s+e)/2;
            
            if(arr[mid] == key)
            return mid;
            
            if(arr[s] <= arr[mid])
            {
                if(arr[s] <= key && arr[mid] >= key )
                {
                    e=mid-1;
                }
                else
                {
                    s=mid+1;
                }
            }
            else
            {
                if(arr[mid] <= key && key <= arr[e])
                {
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
        }
        return -1;
    }
    
};

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter size: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter the values: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int key;
        cout << "Enter the key: ";
        cin >> key;

        Solution ob;
        int result = ob.search(arr, key);
        if (result != -1) {
            cout << "The Index at which the key is Found: " << result << endl;
        } else {
            cout << "Key not found in the array" << endl;
        }
    }

    return 0;
}