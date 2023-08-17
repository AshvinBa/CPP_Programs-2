/*
Second most repeated string in a sequence
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.
Example 1:
Input:
N = 6
arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
Output: bbb
Explanation: "bbb" is the second most 
occurring string with frequency 2.

Example 2:
Input: 
N = 6
arr[] = {geek, for, geek, for, geek, aaa}
Output: for
Explanation: "for" is the second most
occurring string with frequency 2.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string secFrequent (string arr[], int n)
    {
        map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        for(auto x:mp)
        {
            pq.push(make_pair(x.second,x.first));
            
            if(pq.size()>2) pq.pop();
        }
        
        if(pq.size()>1)
        return pq.top().second;
        else
        return "";
        
    }

int main(){
    string arr[]={"aaa","bbb","aaa","ccc","aaa","ddd","ccc"};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<secFrequent (arr,n);   
return 0;
}