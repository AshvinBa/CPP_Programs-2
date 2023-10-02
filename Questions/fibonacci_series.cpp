/*
fibonacci Series.
Enter the number and it give you a fibonacci series oup to that number.
Example-1
IP:
int n=10
Answer: 0 1 1 2 3 5 8 13 21 34 
*/ 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> fibonacci_series(int n)
{
    vector<int>ans;

    if(n==1)
    {
        ans.push_back(0);
        return ans;
    }
    else if(n==2)
    {
        ans.push_back(0);
        ans.push_back(1);
        return ans;
    }
    else
    {
        ans.push_back(0);
        ans.push_back(1);

        for(int i=2;i<n;i++)
        {
            ans.push_back(ans[ans.size()-2]+ans[ans.size()-1]);
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number for fibonacci series: ";
    cin>>n;
    vector<int>ans=fibonacci_series(n);
    cout<<"Answer: ";
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}