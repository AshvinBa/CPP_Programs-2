//  Given Array of size n and a number k, find all elements that appear more than n/k times  //

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> func(vector<int> vec,int n,int k)
{
    int x=n/k;

    unordered_map<int,int> m1;

    for(int i=0;i<n;i++)
    {
        m1[vec[i]]++;
    }

    for(auto i:m1)
    {
        if(i.second>x)
        {
            cout<<i.first<<" ";
        }
    }    
}

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int k=4;

    vector<int>vec{3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4;
    vector<int>ans=func(vec,n,k);
return 0;
}
