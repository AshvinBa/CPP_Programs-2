#include<iostream>
using namespace std;

int onec_occurence(int arr[],int n)
{   
    int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans^arr[i];
        }
    return ans;
}

int main(){
    int arr[]={2,2,3,3,4,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Answer: "<<onec_occurence(arr,n);
return 0;
}

//https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1?page=2&curated[]=1&sortBy=submissions