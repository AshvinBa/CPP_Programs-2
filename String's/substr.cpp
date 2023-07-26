#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str1;
    cout<<"Enter the string: ";
    cin>>str1;
    int index,len;
    cout<<"Enter the index and length: ";
    cin>>index;
    cin>>len;
    cout<<str1.substr(index,len);
return 0;
}