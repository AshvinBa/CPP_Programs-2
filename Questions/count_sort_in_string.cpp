/*
Counting Sort
Given a string arr consisting of lowercase english letters, arrange all its letters in lexicographical order using Counting Sort.

Example 1:
Input:
N = 5
S = "edsab"
Output:
abdes
Explanation: 
In lexicographical order, string will be 
abdes.

Example 2:
Input:
N = 13
S = "geeksforgeeks"
Output:
eeeefggkkorss
Explanation:
In lexicographical order, string will be 
eeeefggkkorss.
Your Task:
This is a function problem. You only need to complete the function countSort() that takes string arr as a parameter and returns the sorted string. The printing is done by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Constraints:
1 ≤ N ≤ 105
*/

/*
//approach -1:

 string countSort(string arr){
        /*
        sort(arr.begin(),arr.end());
        
        string s="";
        for(auto i:arr)
        {
            s+=i;
        }
        return s;
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


 string countSort(string arr){
        vector<int>cnt(26,0);
        for(int i=0;i<arr.size();i++)
        {
            cnt[arr[i]-'a']++;
        }
        for(int i=1;i<26;i++)
        cnt[i]+=cnt[i-1];
        
        string s(arr.length(),' ');
        
        for(int i=0;i<arr.size();i++)
        {
            int x=--cnt[arr[i]-'a'];
            s[x]=arr[i];
        }
        return s;
    }

int main(){
    string arr="abaabc";
    cout<<"\nAnswer: "<<countSort(arr);
return 0;
}