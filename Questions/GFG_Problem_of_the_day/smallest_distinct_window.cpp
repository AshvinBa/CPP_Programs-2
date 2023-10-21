#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int count(int n)
{
    int cnt=0;
    while(n!=0)
    {
        int last=n%10;
        cnt++;
        n=n/10;
    }
    return cnt;
}

bool digit(int n,int cnt)
{
    int ans=0;
    int temp=n;
    if(cnt>3)
    {
        while(n!=0)
        {
            int last=n%10;
            ans+=pow(last,cnt);
            n=n/10;
        }
    }
    else
    {
        while(n!=0)
        {
            int last=n%10;
            ans+=last*last*last;
            n=n/10;
        }
    }
    
    
    if(ans==temp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(){
    int n;
    cout<<"Enter the digit: ";
    cin>>n;
    int cnt=count(n);
    if(digit(n,cnt))
    {
        cout<<"Yes its amstrong.";
    }
    else
    {
        cout<<"No its not amstrong.";
    }
return 0;
}