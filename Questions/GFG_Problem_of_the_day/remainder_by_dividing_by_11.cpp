#include<iostream>
using namespace std;

int divide(int n)
{
    int x=n;
    int ans=0;
    int res=0;
    while(x!=0)
    {
        ans=x%10;
        res=ans%11;
        res+=res*10;
        x=x/11;
    }    
    return res;
}

int main(){
    int n=34;
    cout<<divide(n);
return 0;
}