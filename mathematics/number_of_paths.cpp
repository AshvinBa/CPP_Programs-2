/*
Number of paths
The problem is to count all the possible paths from top left to bottom right of an MxN matrix with the constraints that from each cell you can either move to right or down.

Return answer modulo 109+7.

Example 1:
Input:
M = 3 and N = 3
Output: 6
Explanation:
Let the given input 3*3 matrix is filled 
as such:
A B C
D E F
G H I
The possible paths which exists to reach 
'I' from 'A' following above conditions 
are as follows:ABCFI, ABEHI, ADGHI, ADEFI, 
ADEHI, ABEFI

Example 2:
Input:
M = 1 and N = 4
Output: 1
Explanation:
There is only one direction to go in,
and thus, there is only one path possible.
Your Task
You don't need to read input or print anything. Your task is to complete the function numberOfPaths() which takes the integer M and integer N as input parameters and returns an integer, the number of paths.

Expected Time Complexity: O(M)
Expected Space Complexity: O(1)

Constraints:
1 ≤ N ≤ 108
1 ≤ M ≤ 105

*/

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long  numberOfPaths(int m, int n)
    {
        long long ans=1;
        long long mod=1000000007L;
        
        for(long long i=n;i<=(n+m-2);i++)
        {
            ans=(ans*i)%mod;
            long long invert = modInv(i-n+1,mod);
            ans=(ans*invert)%mod;
        }
        return ans;
    }
    long long pow(long long x,int y,long long mod)
    {
        long long res=1;
        while(y>0)
        {
            if(y%2!=0)
            res=(res*x)%mod;
            
            y=y/2;
            x=(x*x)%mod;
        }
        return res;
    }
    
    long long modInv(long long n,long long mod)
    {
        return pow(n,(int)(mod-2),mod);
    }
    
};


/*

All approaches are failed and not optimised.

long long  numberOfPaths(int m, int n)
    {
        vector<int>mat(n,1);
        
        for(int i=0;i<m-1;i++)
        {
            for(int j=1;j<n;j++)
            {
                mat[j] += mat[j-1];
            }
        }
        
        return mat[n-1];
    }




long long  numberOfPaths(int m, int n)
    {
        vector<vector<int>>mat(m,vector<int>(n,1));
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                mat[i][j] = mat[i-1][j] + mat[i][j-1];
            }
        }
        
        return mat[m-1][n-1];
    }



long long  numberOfPaths(int M, int N)
    {
        if(M==1 || N==1)
        return 1;
        
        return numberOfPaths(M-1,N)+numberOfPaths(M,N-1);
    }

*/

int main()
{
	int t;
    cout<<"Enter the value of t: ";
	cin>>t;
	while(t--)
	{
        cout<<"Enter the value of N and M: ";
		int N, M;
		cin>>M>>N;
		Solution ob;
        cout<<endl<<"Answer: ";
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}






















