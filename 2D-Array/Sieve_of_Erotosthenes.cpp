
#include<iostream>
using namespace std;
bool IsPrime(int n)
{
    if(n<=1)
    return false;

    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false; 
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    bool x=IsPrime(n);
    if(x==1)
    {
        cout<<"The Number is Prime.";
    }
    else
    {
        cout<<"The Number is not Prime.";
    }
return 0;
}