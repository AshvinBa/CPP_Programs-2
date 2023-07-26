#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string str1,string str2)
{
    vector<int>freq(26,0);

    if(str1.length()!=str2.length())
    {
        return false;
    }

    for(int i=0;i<str1.length();i++)
    {
        freq[str1[i]-'a']++;
        freq[str1[i]-'a']--;
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
    string str1{"anagram"};
    string str2{"gramana"};
    if(isAnagram(str1,str2)){
        cout<<"\nYes its anagram.";
    }
    else
    {
        cout<<"Not anagram.";
    }
return 0;
}