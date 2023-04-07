//Problem of the day.
//7-4-2023

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int palin(string str)
{
    int i=0;
    int j=str.length()-1;
    int res=0;
    int ext=j;

    while(i<=j)
    {
        if(str[i]==str[j])
        {
            i++;
            j--;
        }
        else
        {
            res++;
            i=0;
            j=--ext;
        }
    }
    return res;
}
int main(){
    string str="ash";
    int x=palin(str);
    cout<<"The character require to make palindrom is: "<<x;
return 0;
}