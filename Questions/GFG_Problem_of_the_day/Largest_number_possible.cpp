/*
Largest number possible

Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'. Return -1 if it is not possible.
Example 1:
Input: N = 2, S = 9
Output: 90
Explaination: It is the biggest number 
with sum of digits equals to 9.

Example 2:
Input: N = 3, S = 20
Output: 992
Explaination: It is the biggest number 
with sum of digits equals to 20.
Your Task:
You do not need to read input or print anything. Your task is to complete the function findLargest() which takes N and S as input parameters and returns the largest possible number. Return -1 if no such number is possible.
Expected Time Complexity: O(N)
Exepcted Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 104
0 ≤ S ≤ 105

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string findLargest(int N, int S)
{
    string str="";
    if(S!=0 && N==0)
    {
        return "-1";
    }

    for(int i=0;i<N;i++)
    {
        if(S>9)
        {
            str+='9';
            S-=9;
        }
        else
        {
            str+=to_string(S);
            S-=S;
        }
    }

    if(S!=0)
    {
        return "-1";
    }
    else
    {
        return str;
    }
}

int main(){
    int N=3;
    int S=20;
    cout<<"\nAnswer: "<<findLargest(N,S);
return 0;
}