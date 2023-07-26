#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string countString(string str)
{
    vector<int>freq(26,0);

    for(int i=0;i<str.length();i++)
    {
        int index=str[i]-'a';
        freq[index]++;
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
    cout<<"Your Entered string is: "<<str<<endl;
    cout<<"\nAnswer: "<<countString(str);
    return 0;
}