/*

Find first repeated character

Given a string S. The task is to find the first repeated character in it. We need to find the character that occurs more than once and whose index of second occurrence is smallest. S contains only lowercase letters.

Example 1:
Input: S="geeksforgeeks"
Output: e
Explanation: 'e' repeats at third position.
*/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string firstRepChar(string s)
{
    int n=s.length();
    string ans="";
    map<char,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
        if(mp[s[i]]==2)
        {
            ans+=s[i];
            return ans;
        }
    }
    if(ans.length()<=0)
    {
        ans+="-1";
        return ans;
    }
}
int main(){
    string s="assh";
    cout<<"\nAnswer: "<<firstRepChar(s);
return 0;
}