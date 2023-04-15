//A-1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string reverse(string str,int n)
{
    stack<char>s;
    for(int i=0;i<n;i++)
    {
        char ch=str[i];
        s.push(ch);
    }
    string ans="";
    while(!s.empty())
    {
        char ch=s.top();
        s.pop();
        ans.push_back(ch);
    }
    return ans;
}

int main(){
    string str="ashvin";
    int n=str.length();
    cout<<reverse(str,n);
return 0;
}


/*
A-2

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str="ashvin";

    stack<char>s;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        s.push(ch);
    }
    cout<<"The reverse string are: ";
    while(!s.empty())
    {
        char ch=s.top();
        s.pop();
        cout<<ch;
    }
return 0;
}

*/