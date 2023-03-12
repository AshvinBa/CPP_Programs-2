#include<iostream>
using namespace std;
int main(){
    int n;
    
    cout<<"Enter the number: ";
    cin>>n;
    
    int digit=0;
    
    while(n!=0)
    {
        digit++;
        n=n/10;
    }

    cout<<"The number of digit preasent is: "<<digit;
return 0;
}