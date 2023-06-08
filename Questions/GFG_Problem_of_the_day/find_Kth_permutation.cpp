#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Optimal solution than 2nd
/*
string KthPermutation(int n, int k)
{
    vector<int> fact(n + 1, 1);
    
    for (int i = 1; i <= n; i++)
        fact[i] = i * fact[i - 1];
    
    vector<bool> vis(n + 1, false);
    string ans = "";
    int i = n;
    
    while (ans.length() != n)
    {
        int row = k / fact[i - 1];
        if (k % fact[i - 1])
            row++;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == false)
            {
                row--;
            }
            if (row == 0)
            {
                vis[j] = true;
                ans += (j + '0');
                break;
            }
        }
        k = k % fact[i - 1];
        if (k == 0)
            k = fact[i - 1];
        i--;
    }
    return ans;
}
*/

/*1 st solution.*/
string KthPermutation(int n,int k)
{
    vector<int>temp(n);
    for(int i=0;i<n;i++)
    temp[i]=i+1;
    k--;

    while(k--)
    {
        next_permutation(temp.begin(),temp.end());
    }
    string ans="";

    for(auto x:temp)
    {
        ans+=(x+'0');
    }
    return ans;
}

int main()
{
    int n, k;
    cout << "Enter the number of digit for permutation: ";
    cin >> n;
    cout << "Enter at which Number want Permutation: ";
    cin >> k;
    cout << "The Permutation is: ";
    cout << KthPermutation(n, k);
    return 0;
}