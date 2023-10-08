#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool func(vector<int>vec1)
{
    int i=0,j=1;
    int x;
    int n=vec1.size();
    cout<<"Enter the digit: ";
    cin>>x;
    while(i<n and j<n)
    {
        if(abs(vec1[i]-vec1[j])<x)
        {
            j++;
        }
        else if(abs(vec1[i]-vec1[j])==x)
        {
            return true;
        }
        else if(abs(vec1[i]-vec1[j])>x)
        {
            i++;
        }
    }
    return false;
}
int main(){
    int n;
    cout<<"\nDifference: \n";
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