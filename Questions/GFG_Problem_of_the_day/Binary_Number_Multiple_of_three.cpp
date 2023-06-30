/*

Is Binary Number Multiple of 3

Given a number in its binary form find if the given binary number is a multiple of 3. It is recommended to finish the task using one traversal of input binary number.

Example 1:
Input: S = "0011"
Output: 1
Explanation: "0011" is 3, which is divisible by 3.

Example 2:
Input: S = "100"
Output: 0
Explanation: "100"'s decimal equivalent is 4, which is not divisible by 3.

*/


#include<iostream>
using namespace std;

int isDivisible(string s)
{
    int cur=0;
    for(auto i:s)
    {
        cur=cur*2+(i+'0');
    }
    if(cur%3==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(){
    string s="0111";
    cout<<"\nAnswer: "<<isDivisible(s);
return 0;
}
