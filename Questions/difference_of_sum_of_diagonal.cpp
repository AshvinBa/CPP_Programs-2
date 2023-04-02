#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the limits: ";
    cin>>n;
    int arr[n][n];
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"\nThe Matrix is: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int sumL=0;
    int sumR=0;

    int i=0,j=0;
    while(i<n && j<n)
    {
        sumL+=arr[i][j];
        i++;
        j++;
    }
    i=0,j=n-1;
    while(i<n && j>=0)
    {
        sumR+=arr[i][j];
        i++;
        j--;
    }
    int Tsum=abs(sumL-sumR);
    cout<<"The Difference of the two diagoal is: "<<Tsum<<endl;
return 0;
}