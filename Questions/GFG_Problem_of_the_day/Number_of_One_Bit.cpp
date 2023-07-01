#include<iostream>
using namespace std;

int func(int N)
{
    int ans=0;
    while(N)
    {
        ++ans;
        N&=(N-1);
    }
    return ans;
}


// Approach 1 broothforce approach and Not able to pass all the conditions.
// int func(int N)
// {
//     int power=1;
//         int ans=0;
//         while(N>0)
//         {
//             int last=N%2;
//             ans=ans+last*power;
//             power=power*10;
//             N/=2;
//         }
//         int n=ans;
//         cout<<n;
//         int cnt=0;
//         while(n!=0)
//         {
//             int digit=n%10;
//             if(digit==1)
//             {
//                 cnt++;
//             }
//             n/=10;
//         }
//         return cnt;
// }

int main(){
    int N=5;
    cout<<"\nAnswer: "<<func(N);
return 0;
}