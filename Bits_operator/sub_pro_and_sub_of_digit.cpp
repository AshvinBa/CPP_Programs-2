#include<iostream>
using namespace std;

int difference(int n)
{
    int last=0;
    int prod=1;
    int sum=0;
    while(n!=0)
    {
        last=n%10;
        sum=sum+last;
        prod=prod*last;
        n=n/10;
    }
    return abs(prod-sum);
}

int main()
{
    int n;
    cout<<"Enter the digit: ";
    cin>>n;
    cout<<"\nThe difference of sum and product is: "<<difference(n);

return 0;
}