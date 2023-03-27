#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    int c1=0;
    int c2=0;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        if(str[i]=='*' || str[i]=='#')
        {
            if(str[i]=='*')
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        else
        {
            continue;
        }
    }
    if(c1>c2)
    {
        cout<<"Greater the number of star.";
    }
    else if(str.empty())
    {
        cout<<"Not found.";
    }
    else if(c1<c2)
    {
        cout<<"Smaller the number of star.";
    }
    else if(c1==c2)
    {
        cout<<"Both are equal.";
    }
return 0;
}