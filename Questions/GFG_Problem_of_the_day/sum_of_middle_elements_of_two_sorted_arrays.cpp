#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int findMidSum(int arr1[], int arr2[], int n) 
{
    vector<int>arr;

    for(int i=0;i<n;i++)
    {
        arr.push_back(arr1[i]);
    }

    for(int i=0;i<n;i++)
    {
        arr.push_back(arr2[i]);
    }

    sort(arr.begin(),arr.end());

    int s=0;
    int e=arr.size()-1;
    int mid=(s+e)/2;
    int sum=arr[mid]+arr[mid+1];
   
    return sum;
}
int main(){
    
    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};
    int n=sizeof(arr1)/sizeof(arr1[0]); 
    cout<<"Answer: "<<findMidSum(arr1, arr2, n);

return 0;
}