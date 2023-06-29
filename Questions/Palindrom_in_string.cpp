#include<iostream>
using namespace std;

int palindrom(string s)
{
    int i=0;
    int n=s.length();
    int j=n-1;

    while(i<=j)
    {
        if(s[i]!=s[j])
        {
            return 0;
        }
        else
        {
            i++;
            j--;
        }
    }
    return 1;
}

int main(){
    string s="a1bb1a";
    int x=palindrom(s);
    if(x)
    {
        cout<<"Palindrom.";
    }
    else
    {
        cout<<"Not Palindrom.";
    }
return 0;
}