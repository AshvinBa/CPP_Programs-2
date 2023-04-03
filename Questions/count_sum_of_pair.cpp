/*In Sorted array*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getsum(vector<int> vec,int n,int digit)
{
    int cnt=0;
    int s=0;
    int e=n-1;
    while(s<e)
    {
        if(vec[s]+vec[e]==digit)
        {
            cnt++;
            s++;
            e--;
        }
        else if((vec[s]+vec[e])<=digit)
        {
            s++;
        }
        else if((vec[s]+vec[e])>=digit)
        {
            e--;
        }
    }
    return cnt;
}

int main(){
    int n;
    cout<<"ENter the limit: ";
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    int digit;
    cout<<"Enter the digit: ";
    cin>>digit;
    cout<<"The num: "<<getsum(vec,n,digit);
return 0;
}