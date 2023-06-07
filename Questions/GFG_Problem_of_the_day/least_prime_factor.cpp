#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> check(int n)
{
    vector<int> ans(n+1,0);
    ans[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(ans[i]==0)
        {
            ans[i]=i;
            for(int j=2*i;j<=n;j+=i)
            {
                if(ans[j]==0)
                {
                    ans[j]=i;
                }
            }
        }
    }
    return ans;    
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<int> res = check(n);
    for (auto i = res.begin(); i != res.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}