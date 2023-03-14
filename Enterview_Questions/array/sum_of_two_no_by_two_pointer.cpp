#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool func(vector<int>vec1)
{
    int i=0,j=vec1.size();
    int x;
    cout<<"Enter the digit: ";
    cin>>x;
    while(i<j)
    {
        if(vec1[i]+vec1[j]<x)
        {
            i++;
        }
        else if(vec1[i]+vec1[j]==x)
        {
            return true;
        }
        else if(vec1[i]+vec1[j]>x)
        {
            j--;
        }
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter the limits: ";
    cin>>n;
    vector<int>vec1(n);
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>vec1[i];
    }
    int x=func(vec1);
    if(x==1)
    {
        cout<<"\nYes.";
    }
    else 
    {
        cout<<"\nNo.";
    }
return 0;
}