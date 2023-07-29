#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool isomorphic(string s1,string s2)
{
    vector<int>v1(128,-1);
    vector<int>v2(128,-1);

    if(s1.length()!=s2.length())
    {
        return false;
    }

    for(int i=0;i<s1.length();i++)
    {
        if(v1[s1[i]]!=v2[s2[i]])
        {
            return false;
        }
        v1[s1[i]]=v2[s2[i]]=i;
    }
    return true;
}

int main(){
    string s1,s2;
    cout<<"Enter the string s1: ";
    cin>>s1;
    cout<<"Enter the string s2: ";
    cin>>s2;
    if(isomorphic(s1,s2))
    {
        cout<<"The string is isomorphic.";
    }
    else
    {
        cout<<"The string is not isomorphic.";
    }
return 0;
}