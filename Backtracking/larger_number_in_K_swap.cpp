/*
Largest number in K swaps
Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.

Example 1:
Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5

Example 2:
Input:
K = 3
str = "3435335"
Output:
5543333
Explanation:
Three swaps can make the input
3435335 to 5543333, swapping 3 
with 5, 4 with 5 and finally 3 with 4 

Your task:
You don't have to read input or print anything. Your task is to complete the function findMaximumNum() which takes the string and an integer as input and returns a string containing the largest number formed by perfoming the swap operation at most k times.

Expected Time Complexity: O(n!/(n-k)!) , where n = length of input string
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ |str| ≤ 30
1 ≤ K ≤ 10

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    void solve(string str,int n,int k,string &ans,int index)
    {
        if(k==0)
        return;
        
        char maxchar=str[index];
        
        for(int i=index+1;i<n;i++)
        {
            if(maxchar<str[i])  // check karo kya maxchar chota hai current char se.
            maxchar=str[i];
        }
        
        if(maxchar!=str[index]) //matlab swap karchuke hai.
        k--;    // swap ko decrease kardo.
        
        for(int i=n-1;i>=index;i--)
        {
            if(str[i]==maxchar)
            {
                swap(str[index],str[i]);
                if(ans<str)
                ans=str;
                
                solve(str,n,k,ans,index+1);
                swap(str[index],str[i]);  //backtracking.
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
        string ans=str;
        int n=str.size();
        solve(str,n,k,ans,0);
        return ans;
    }
};

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
