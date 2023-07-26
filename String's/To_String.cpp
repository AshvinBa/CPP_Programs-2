#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string To_string(int n)
{
    string str=to_string(n);
    str+="1";
    return str;    
}

int main(){
    int n;
    cout<<"Entert he digit: ";
    cin>>n;
    cout<<"\nAnswer: "<<To_string(n);
return 0;
}