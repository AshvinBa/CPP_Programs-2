#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the digit: ";
    cin>>n;
    int result=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            result-=i;
        }
        else
        {
            result+=i;
        }
    }
    
    cout<<"The sum of the series is: "<<result;

return 0;
}

/*
output

Enter the digit: 13
The sum of the series is: 7
*/