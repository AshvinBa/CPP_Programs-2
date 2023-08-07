#include<iostream>
using namespace std;



int number_of_bit(int n)
{
    int ans=0;
    int last=0;
    int power=1;
    while(n!=0)
    {
        last=n%2;
        ans=ans+last*power;
        power*=10;
        n=n/2;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the digit: "<<endl;
    cin>>n;
    int ans=number_of_bit(n);

    int last=0;
    int cnt=0;
    while(ans!=0)
    {
        last=ans%10;
        if(last&1)     //and operator use to check 1's.
        {
            cnt++;
        }
        ans=ans/10;
    }
    cout<<"The Number of 1s is: "<<cnt;
return 0;
}






