#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int x;
    cout<<"Entre the limit of digits: ";
    cin>>n;
    int occr=0;
    cout<<"Enter the values: ";
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    
    cout<<"Enter the value of x: ";
    cin>>x;
    for(int i=0;i<n;i++)
    {
        if(vec[i]>x)
        occr++;
    }
    cout<<occr;
return 0;
}