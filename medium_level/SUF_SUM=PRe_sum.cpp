#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool func(vector<int>&vec,int n)
{
    int pref_sum=0;
    int suf_sum=0;
    int total_sum=0;

    for(int i=0;i<n;i++)
    {
        total_sum+=vec[i];
    }

    for(int i=0;i<n;i++)
    {
        pref_sum+=vec[i];
        suf_sum=total_sum-pref_sum;

        if(suf_sum==pref_sum)
        {
            return true;
        }
    }
}
int main(){
    vector<int>vec{10,10,10,10,10};
    int n=vec.size();
    int x=func(vec,n);
    if(x==1)
    {
        cout<<"YES!...Both are Equal.";
    }
    else
    {
        cout<<"NO!...Its Not Equal.";
    }
return 0;
}