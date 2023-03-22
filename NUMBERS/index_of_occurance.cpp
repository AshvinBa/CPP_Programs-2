#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int digit;
    cout<<"Enter the limits: ";
    cin>>n;
    cout<<"Enter the numbers: "; 
    vector<int>vec(n);
    for(int i=1;i<=n;i++)
    {
        cin>>vec[i];
    }
    int index=-1;
    cout<<"Enter the digit for search: ";
    cin>>digit;
    for(int i=1;i<=n;i++)
    {
        if(vec[i]==digit)
        index=i;
    }
    cout<<"Occure at index= "<<index;
return 0;
}