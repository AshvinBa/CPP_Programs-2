#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(a<=0)
    return b;

    if(b>a)
    return gcd(b,a);

    return gcd(a-b,b);
}
int main(){
    int a,b;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;
    cout<<gcd(a,b);
return 0;
}