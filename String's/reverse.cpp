#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    
    reverse(str.begin(),str.end());
    cout<<"Answer: ";
    cout<<str;
return 0;
}