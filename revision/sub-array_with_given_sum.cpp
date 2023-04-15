#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>sum_of_subarray(vector<int>&vec,int s,int n)
{
    int i=1,j=1;
    vector<int>res;
    int ans=0;
    while(i<n && j<n)
    {
        if(ans<s)
        {
            ans+=vec[j];
            j++;
        }
        else
        {
            ans-=vec[i];
            i++;
        }
        if(ans==s)
        {
            res.push_back(i+1);
            res.push_back(j);
        }
    }
    return res;    
}

int main(){
    vector<int>vec{1,2,3,7,5};
    int s=12;
    int n=vec.size();
    vector<int>result=sum_of_subarray(vec,s,n);
    cout<<"Answer: ";
    for(auto i=result.begin();i!=result.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}