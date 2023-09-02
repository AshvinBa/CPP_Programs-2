// Union of Two Sorted array

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i=0,j=0;
        vector<int>ans;
        while(i<n and j<m)
        {
            if(arr1[i]==arr2[i])
            {
                ans.push_back(arr1[i]);
                i++;
                j++;
            }
            else if(i<n and arr1[i]<arr2[j])
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else if(j<m and arr1[i]>arr2[j])
            {
                ans.push_back(arr2[i]);
                j++;
            }
        }
        while(i<n)
        {
            ans.push_back(arr1[i]);
            i++;
        }
        while(j<m)
        {
            ans.push_back(arr2[j]);
            j++;
        }
        return ans;
    }

int main(){
    int a1[]={1,2,3,4,5,6};
    int a2[]={2,3,5,6};
    int n=6;
    int m=4;
    vector<int>ans= findUnion(a1,a2,n,m);
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
return 0;
}