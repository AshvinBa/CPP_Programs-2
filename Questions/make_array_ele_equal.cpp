#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> arr_equal(vector<int>&arr,int n)
{
    int ash[n]={0};
    vector<int>ans;

    for(int i=0;i<n;i++)
    {
        ash[arr[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        if(ash[i]>1)
        {
            ans.push_back(i);
        }
    }
    if(ans.size()==0)
    {
        ans.push_back(-1);
    }
    return ans;
}


int main(){
    vector<int>arr{1,2,3,8,9,10,3,3,3,5,5,5,1,1,1,1,4,5,1};
    int n=arr.size();

    vector<int>x=arr_equal(arr,n);
    
    cout<<"\nAnswer: ";
    for(auto i=x.begin();i!=x.end();i++)
    {
        cout<<*i<<" ";
    }

return 0;
}