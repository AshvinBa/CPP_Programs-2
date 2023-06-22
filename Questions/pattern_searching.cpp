/*
Pattern searching
Given a string str and a pattern pat. You need to check whether the pattern is present or not in the given string. 

Example 1:-

Input:
2
abcdefh
bcd
axzy
xy

Output:
Present
Not present
*/

#include<iostream>
using namespace std;

int Sub(string str1,string str2)
{
    while(str1.find(str2)!=string::npos)
    {
        return 1;
    }
    return 0;
}

int main(){
    string str1="abcdef";
    string str2="abd";
    int x=Sub(str1,str2);    
    if(x==1)
    {
        cout<<"Yes Preasent.";
    }
    else
    {
        cout<<"Not Preasent.";
    }
return 0;
}