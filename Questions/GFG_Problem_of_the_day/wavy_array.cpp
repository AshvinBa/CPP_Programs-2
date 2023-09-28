/*

Wave Array.

Example-1

Input:
n=5
arr[]={1,2,3,4,5}
output:
2 1 4 3 5


Example-2

Input:
n=6
arr[]={6,7,9,10,11,18}
output:
7 6 10 9 18 11

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void convertToWave(int n, vector<int>& arr){
        
        for(int i=0;i<n;i+=2)
        {
            if(i+1!=n)
            {
            swap(arr[i],arr[i+1]);
            }
        }
        
    }
int main(){
    int n=5;
    vector<int>arr{1,2,3,4,5};
    convertToWave(n,arr);
    cout<<"Answer: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}