#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int lastdigit=0;
    int sum=0;
    while(n!=0)
    {
        lastdigit=n%10;
        sum+=lastdigit;
        n/=10;    
    }
    cout<<"Sum of the Digit is: "<<sum;
return 0;
}

/*
output

Enter the number: 123456
Sum of the Digit is: 21
*/