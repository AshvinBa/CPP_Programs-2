#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the numbers: ";
    cin>>n;
    int ans=0;
    int lastdigit=0;
    int digit=0;
    while(n!=0)
    {
        lastdigit=n%10;
        // if((ans>INT16_MAX/10)||(ans<INT16_MIN/10))
        // {
        //     return 0;
        // }
        ans=ans*10+lastdigit;
        n=n/10;
    }
    cout<<ans;
return 0;
}

/*

Enter the numbers: 123456

654321
*/