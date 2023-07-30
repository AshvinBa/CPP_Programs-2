#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int  longest_Ones(string str,int k)
{
    int start=0;
    int end;
    int maxlen=0;
    int zero_cnt=0;

    for(end=0;end<str.length()-1;end++)
    {
        if(str[end]=='0')
        {
            zero_cnt++;
        }
    }

    while(zero_cnt>k)
    {
        if(str[start]=='0')
        zero_cnt--;
        start++;
    }
    maxlen=max(maxlen,end-start+1);
    return maxlen;
}

int main(){
    string str;
    int k;
    cout<<"Enter the string: ";
    cin>>str;
    cout<<"Enter the value K: ";
    cin>>k;
    cout<<"\nAnswer: "<<longest_Ones(str,k);
return 0;
}