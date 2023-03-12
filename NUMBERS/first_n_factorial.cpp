#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int digit=1;
    for(int i=1;i<=n;i++)
    {
        digit*=i;
    }
    cout<<digit;
return 0;
}

/*
output

Enter the value of n: 4
24
*/