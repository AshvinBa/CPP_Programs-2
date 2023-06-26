/*
Array Subset of another array
Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. There can be duplicate elements.
 

Example 1:
Input:
a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
a2[] = {11, 3, 7, 1, 7}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 2:
Input:
a1[] = {1, 2, 3, 4, 4, 5, 6}
a2[] = {1, 2, 4}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 3:
Input:
a1[] = {10, 5, 2, 23, 19}
a2[] = {19, 5, 3}
Output:
No
Explanation:
a2[] is not a subset of a1[]
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int isSubset(int a1[], int a2[], int n, int m) {
    
    unordered_map<int,int>mp;
    
    for(int i=0;i<n;i++)
    {
        mp[a1[i]]++;
    }
    
    int c=0;
    
    for(int i=0;i<m;i++)
    {
        if(mp[a2[i]])
        {
            c++;
        }
    }
    
    if(c!=m) return 0;
    else return 1;
}


int main(){
    int a1[]={1,2,3,4,5,6};
    int a2[]={1,2,3};
    int n=sizeof(a1)/sizeof(a1[0]);
    int m=sizeof(a2)/sizeof(a2[0]);
    int x=isSubset(a1,a2,n,m);
    cout<<"Answer: "<<x;
return 0;
}



// approach 2

    // unordered_map<int,int>mp;
    
    // for(int i=0;i<n;i++)
    // {
    //     mp[a1[i]]=i;
    // }
    
    // for(int i=0;i<m;i++)
    // {
    //     if(mp.find(a2[i]) == mp.end())
    //     {
    //         return "No";
    //     }
    // }
    // return "Yes";
