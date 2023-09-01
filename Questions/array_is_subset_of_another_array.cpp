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


// Approach - 1
/*
string isSubset(int a1[], int a2[], int n, int m) {
unordered_map<int,int>ans;
    
    for(int i=0;i<n;i++)
    {
        ans[a1[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        ans[a2[i]]--;
    }
    
    int cnt=0;
    
    for(auto j:ans)
    {
        if(j.second==0)
        {
            cnt++;
        }
    }
    
    if(cnt==m)
        return "Yes";
    else
        return "No";
}*/

/*
string isSubset(int a1[], int a2[], int n, int m) {

int cnt=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[a1[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        if(mp[a2[i]])
        {
            cnt++;
        }
    }
    if(cnt==m)
    return "Yes";
    else
    return "No";
}
*/

/*
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,bool>mp;
    for(int i=0;i<n;i++)
    {
        mp[a1[i]]=true;
    }
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        if(mp[a2[i]]==true)
        {
            cnt++;
        }
    }
    
    if(cnt==m)
    return "Yes";
    else
    return "No";
    
}
*/

/*
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[a1[i]]=i;
    }
    for(int i=0;i<m;i++)
    {
        if(mp.find(a2[i])==mp.end())
        {
            return "No";
        }
    }
    return "Yes";
}
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string isSubset(int a1[], int a2[], int n, int m) {
    
    unordered_map<int,int>mp1;
    unordered_map<int,int>mp2;
    
    for(int i=0;i<n;i++){
        mp1[a1[i]]++;
    }
    
    for(int i=0;i<m;i++)
    {
        mp2[a2[i]]++;
    }
    
    for(auto it:mp2)
    {
        if(mp1[it.first]<it.second)
        {
            return "No";
        }
    }
    return "Yes";
}

int main()
{
    int a1[]={4,5,7,8,3};
    int n=5;
    sort(a1,a1+n);
    cout<<"Answer: ";
    for(int i=0;i<n;i++)
    {
        cout<<a1[i]<<" ";
    }
    return 0;
}

















