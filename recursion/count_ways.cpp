#include<iostream>
using namespace std;
int func(int n)
{
    if(n<0)
    return 0;

    if(n==0)
    return 1;

    
    int ans=func(n-1)+func(n-2);
    return ans;
}
int main(){
    int n;
    cout<<"\nEnter the values: ";
    cin>>n;
    cout<<func(n);
return 0;
}

