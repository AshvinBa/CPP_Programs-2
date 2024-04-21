/*

Count Derangements (Permutation such that no element appears in its original position)
A Derangement is a permutation of n elements, such that no element appears in its original position. 
For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
Given a number n, find the total number of Derangements of a set of n elements.

Examples : 

1)
Input: n = 2
Output: 1
For two elements say {0, 1}, there is only one 
possible derangement {1, 0}

2)
Input: n = 3
Output: 2
For three elements say {0, 1, 2}, there are two 
possible derangements {2, 0, 1} and {1, 2, 0}

3)
Input: n = 4
Output: 9
For four elements say {0, 1, 2, 3}, there are 9
possible derangements {1, 0, 3, 2} {1, 2, 3, 0}
{1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3,
1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1} and {3, 2, 1, 0}
*/

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

/*
Program 1)
Approach - 1 : Recursion.

long long int countDerangement(int n)
{

    if(n==1)
    return 0;
    if(n==2)
    return 1;

    int ans=(((n-1)%MOD)*((countDerangement(n-1)%MOD) + ((countDerangement(n-2)%MOD) )));

    return ans;
}

int main()
{
    int n;
    cout<<"Enter the value of N: ";
    cin>>n;
    cout<<countDerangement(n);
    return 0;
}
*/



/*
Program - 2)
Approach - 2.

long long int solveMen(int n,vector<long long int >&dp)
{
    if(n==1)
    return 0;
    if(n==2)
    return 1;

    if(dp[n]!=-1)
    return dp[n];

    dp[n]=(((n-1)%MOD)*((solveMen(n-1,dp)%MOD) + ((solveMen(n-2,dp)%MOD) )));

    return dp[n];
}

long long int countDerangement(int n)
{
    vector<long long int>dp(n+1,-1);
    return solveMen(n,dp);
}

int main()
{
    int n;
    cout<<"Enter the value of N: ";
    cin>>n;
    cout<<countDerangement(n);
    return 0;
}
*/


/*
Program - 3:
Approach - 3.

long long int solveTab(int n)
{
    vector<long long int>dp(n+1,0);

    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++)
    {
        long long int first=dp[i-1]%MOD;
        long long int second=dp[i-2]%MOD;
        long long int sum=(first+second)%MOD;

        long long int ans=((i-1)*sum)%MOD;

        dp[i]=ans;
    }
    return dp[n];

}

long long int countDerangement(int n)
{
    return solveTab(n);
}

int main()
{
    int n;
    cout<<"Enter the value of N: ";
    cin>>n;
    cout<<countDerangement(n);
    return 0;
}

*/

/*

Program - 4)
Approach - 4 

long long int solveSpaceOpt(int n)
{
    long long int prev2=0;
    long long int prev1=1;

    for(int i=3;i<=n;i++)
    {
        long long int first=prev1%MOD;
        long long int second=prev2%MOD;
        long long int sum=(first+second)%MOD;
        long long int ans=((i-1)*sum)%MOD;

        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}

int main()
{
    int n;
    cout<<"Enter the value of N: ";
    cin>>n;
    cout<<solveSpaceOpt(n);
    return 0;
}

*/
