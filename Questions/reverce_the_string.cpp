#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void reverse_string(char str[],int len)
{
    int i=0;
    int j=len-1;
    while(i<=j)
    {
        swap(str[i++],str[j--]);
    }
}
int main(){
    char str[500]="irab nivhsA";
    int len=strlen(str);
    cout<<"The string is: ";
    for(int i=0;i<len;i++)
    {
        cout<<str[i];
    }
    reverse_string(str,len);
    cout<<"\nThe reverse string is: ";
    for(int i=0;i<len;i++)
    {
        cout<<str[i];
    }
return 0;
}