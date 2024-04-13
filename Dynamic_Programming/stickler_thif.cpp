/*
Stickler Thief

Stickler the thief wants to loot money from a society having n houses in a single line. 
He is a weird person and follows a certain rule when looting the houses. According to 
the rule, he will never loot two consecutive houses. At the same time, he wants to 
maximize the amount he loots. The thief knows which house has what amount of money but 
is unable to come up with an optimal looting strategy. He asks for your help to find 
the maximum money he can get if he strictly follows the rule. ith house has a[i] amount 
of money present in it.

Example 1:
Input:
n = 5
a[] = {6,5,5,7,4}
Output: 
15
Explanation: 
Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6+5+4=15.

Example 2:
Input:
n = 3
a[] = {1,5,3}
Output: 
5
Explanation: 
Loot only 2nd house and get maximum amount of 5.
Your Task:
Complete the functionFindMaxSum() which takes an array arr[] and n as input which 
returns the maximum money he can get following the rules.

Expected Time Complexity:O(N).
Expected Space Complexity:O(1).

Constraints:
1 ≤ n ≤ 105
1 ≤ a[i] ≤ 104
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        int prev2=0;
        int prev1=arr[0];
        
        for(int i=1;i<n;i++)
        {
            int incl=prev2+arr[i];
            int excl=prev1+0;
            
            int ans=max(incl,excl);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
};
int main()
{
    //taking total testcases
	int t;
    cout<<"Enter the number of test cases: ";
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
        cout<<"Enter the size: ";
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
        cout<<"Enter the values: ";
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
        cout<<"The maximum value is: ";
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
