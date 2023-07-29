#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string sort_string(string str)
{
    vector<int>freq(26,0);

    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-'a']++;
    }

    int j=0;
    for(int i=0;i<26;i++)
    {
        while(freq[i]--)
        {
            str[j++]=i+'a';
        }
    }
    return str;
}

int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    cout<<sort_string(str);
return 0;
}