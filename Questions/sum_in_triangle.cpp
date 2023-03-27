#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the element: ";
    cin>>n;
    int k=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<setw(3)<<k++<<" ";
        }
        cout<<endl;
    }
return 0;
}