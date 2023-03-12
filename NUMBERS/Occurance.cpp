/*check the occurance*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int occurance=0;
    int digit;
    cout<<"Enter the limits of vector: ";
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    cout<<"\nThe array is: \n";
    for(int i=0;i<n;i++)
    {
    cout<<vec[i]<<" ";
    }
    
    cout<<"\nEnter the digit for counting: ";
    cin>>digit;
    for(int i=0;i<n;i++)
    {
        if(vec[i]==digit)
        occurance++;
    }
    cout<<"The occurance is: "<<occurance;
return 0;
}