#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>&arr,int size)
{
    int x=size;
    set<int> s(arr.begin(),arr.end());
    int y=s.size();
    if(x==y)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main(){
    vector<int> arr{1,2,32,12,3};
    int size=arr.size();
    int n=check(arr,size);
    if(n==0)
    {
        cout<<"False";
    }
    else
    {
        cout<<"True";
    }
return 0;
}