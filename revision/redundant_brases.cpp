#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool redundant(string str)
{
    stack<int>s;

    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch=='('||ch=='+'||ch=='-'||ch=='/'||ch=='*')
        {
            s.push(ch);
        }
        else
        {
            if(ch==')')
            {
                bool isRedundant=true;
                while(s.top()!='(')
                {
                char top=s.top();
                if(top=='*'||top=='-'||top=='+'||top=='/')
                {
                    isRedundant=false;
                }
                s.pop();
                }
                if(isRedundant==true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    string str="()((+)+)";
    bool x=redundant(str);
    if(x)
    {
        cout<<"Redundant.";
    }
    else
    {
        cout<<"Not Redundant.";
    }
return 0;
}