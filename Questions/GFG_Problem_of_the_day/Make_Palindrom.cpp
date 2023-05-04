/*
Make Palindrome.

You are given an array of strings arr of size n. You have to find out if it is possible to make a palindromic string by concatenating the strings in any order. Provided that all the strings given in the array are of equal length.

Example 1:
Input:
n = 4
arr = {"djfh", "gadt", "hfjd", "tdag"}
Output:
YES
Explanation:
You can make the string "djfhgadttdaghfjd", by concatenating the given strings which is a palindrome.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool makePalindrome(int n,vector<string> &arr){
    unordered_map<string,int> mp;
       for(auto seit:arr)
       {
           string cir=seit;
           reverse(cir.begin(),cir.end());
           if(mp.find(cir)!=mp.end())
           {
               mp[cir]--;
               if(mp[cir]==0)
               mp.erase(cir);
           }
           else
           {
               mp[seit]++;
           }
       }
       if(mp.size()==0)
       return true;
       
       if(mp.size()==1)
       {
           string curr=mp.begin()->first;
           string rev=curr;
           reverse(rev.begin(),rev.end());
           return rev==curr;
       }
       return false;
    }

int main()
{
    vector<string>str{"djfh", "gadt", "hfjd", "tdag"};
    int n=str.size();   
    if(makePalindrome(n,str))
    {
        cout<<"Yes.";
    }
    else
    {
        cout<<"No.";
    }
return 0;
}
