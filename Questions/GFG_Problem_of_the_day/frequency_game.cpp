#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        int temp=0;
        int f=INT_MAX;
        for(auto it:mp)
        {
            if(it.second<f)
            {
                temp=it.first;
                f=it.second;
            }
            else if(it.second==f)
            {
                temp=max(temp,it.first);
            }
        }
        return temp;
    }

int main(){
    int arr[]={2,2,5,50,1};
    int n=5;
    cout<<"Answer: "<<LargButMinFreq(arr,n);

return 0;
}