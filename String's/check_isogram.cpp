/*
Check if a string is Isogram or not
Given a string S of lowercase alphabets, check if it is isogram or not. An Isogram is a string in which no letter occurs more than once.

Example 1:

Input:
S = machine
Output: 1
Explanation: machine is an isogram
as no letter has appeared twice. Hence
we print 1.
Example 2:

Input:
S = geeks
Output: 0
Explanation: geeks is not an isogram
as 'e' appears twice. Hence we print 0.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isIsogram(string s)
    {
        
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        for(auto i:mp)
        {
            if(i.second!=1)
            {
                return false;
            }
        }
        return true;
    }

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;

    if(isIsogram(s))
    {
        cout<<"Yes its isogram.";
    }        
    else
    {
        cout<<"Not isogram.";
    }
return 0;
}