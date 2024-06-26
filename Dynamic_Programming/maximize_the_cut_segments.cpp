/*
Maximize The Cut Segments

Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.
Note: if no segment can be cut then return 0.

Example 1:
Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.

Example 2:
Input:
N = 5
x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.
Your Task:
You only need to complete the function maximizeTheCuts() that takes n, x, y, z as parameters and returns max number cuts.

Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)

Constraints
1 <= N, x, y, z <= 104
*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        
        for(int i=1;i<=n;i++)
        {
            if(i-x >= 0 && dp[i-x]!=-1)
                dp[i]=max(dp[i],dp[i-x]+1);
                
            if(i-y >= 0 && dp[i-y]!=-1)
                dp[i]=max(dp[i],dp[i-y]+1);    
                
            if(i-z >= 0 && dp[i-z]!=-1)
                dp[i]=max(dp[i],dp[i-z]+1);    
        }
        
        if(dp[n] < 0)
            return 0;
        else
            return dp[n]; 
    }
};

int main() {
    
    //taking testcases
    int t;
    cout<<"Entre the nuber of test cases: ";
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cout<<"Enter the size: ";
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cout<<"Enter the values of x,y and z: ";
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<"The answer is: ";
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;
    }
	return 0;
}