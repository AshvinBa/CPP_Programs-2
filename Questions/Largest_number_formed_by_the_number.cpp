/*
Largest Number formed from an Array

Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.The result is going to be very large, hence return the result in the form of a string.

Example 1:
Input: 
N = 5
Arr[] = {3, 30, 34, 5, 9}
Output: 9534330
Explanation: Given numbers are {3, 30, 34,
5, 9}, the arrangement 9534330 gives the
largest value.

Example 2:
Input: 
N = 4
Arr[] = {54, 546, 548, 60}
Output: 6054854654
Explanation: Given numbers are {54, 546,
548, 60}, the arrangement 6054854654 
gives the largest value.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function printLargest() which takes the array of strings arr[] as parameter and returns a string denoting the answer.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
0 ≤ Arr[i] ≤ 1018
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	static bool comparator(string s1,string s2)
	{
	    string first=s1+s2;
	    string second=s2+s1;
	    
	    for(int i=0;i<first.size();i++)
	    {
	        if(first[i]>second[i])
	        {
	            return true;
	        }
	        else if(first[i]<second[i])
	        {
	            return false;
	        }
	    }
	    return false;
	}
	
	string printLargest(vector<string> &arr) {
	    
	    int n=arr.size();
	    
	    string res="";
	    sort(arr.begin(),arr.end(),comparator);
	    for(int i=0;i<n;i++)
	    {
	        res.append(arr[i]);
	    }
	    return res;
	}
};

int main() {
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n, i;
        cout<<"Enter the size of array: ";
        cin >> n;
        vector<string> arr(n);
        cout<<"Enter the values :";
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        cout<<"Answer :";
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}