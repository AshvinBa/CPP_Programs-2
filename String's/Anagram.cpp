#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string a,string b)
{
    vector<int>freq(26,0);

    if(a.length()!=b.length())
    {
        return false;
    }

    for(int i=0;i<a.length();i++)
    {
        freq[a[i]-'a']++;
        freq[b[i]-'a']--;
    }

    for(int i=0;i<26;i++)
    {
        if(freq[i]!=0)
        {
            return false;
        }
    }
    return true;
}

int main(){
    string a,b;
    cout<<"Enter the string: ";
    cin>>a>>b;

    if(isAnagram(a,b))
    {
        cout<<"Strings are anagram.";
    }
    else
    {
        cout<<"String is not anagram.";
    }

return 0;
}