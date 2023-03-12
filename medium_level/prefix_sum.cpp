#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int func(vector<int>&vec,int n)
{
    int ans=0;
    for(int each:vec)
    {
        ans+=each;
    }
    return ans;
}
int main(){
    vector<int> vec{10,20,30,40,50};
    int n=vec.size();
    cout<<func(vec,n);
return 0;
}