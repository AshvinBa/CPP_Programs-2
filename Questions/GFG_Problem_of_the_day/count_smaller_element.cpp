/*
Count Smaller elements

Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].

Examples:

Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
Output: [6, 1, 1, 1, 0, 1, 0]
Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.

Input: arr[] = [1, 2, 3, 4, 5]
Output: [0, 0, 0, 0, 0]
Explanation: There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.

Expected Time Complexity: O(n*logn)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i]  ≤ 108

*/


    /*
    Approach -1  Failed at test case number - 1115
    
    vector<int> constructLowerArray(vector<int> &arr) {
        
        vector<int>ans;
        
        for(int i=0;i<arr.size();i++)
        {
            int cnt=0;
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[i]>arr[j])
                {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    int binarySearch(vector<int> &temp, int key)
    {
        int index = -1, low=0, high = temp.size()-1, mid;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            if(temp[mid]==key)
            {
                index=mid;
                high=mid-1;
            }
            else if(temp[mid] > key)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return index;
    }
  
    vector<int> constructLowerArray(vector<int> &arr) {
        
        vector<int>ans;
        vector<int>temp;
        
        for(auto x:arr)
        temp.push_back(x);
        sort(temp.begin(),temp.end());
        
        for(int i=0;i<arr.size();i++)
        {
            int index = binarySearch(temp,arr[i]);
            ans.push_back(index);
            temp.erase(temp.begin()+index);
        }
        return ans;
    }
};

int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}