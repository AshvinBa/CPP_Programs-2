/*
Find Number
MediumAccuracy: 56.78%Submissions: 16K+Points: 4
Win Vouchers, 2X Geekbits & much more! Register for GFG Weekly #100 Now!
Click here to Enter 

Given an integer N, You need to find the Nth smallest number which only contains odd digits i.e. 1,3,5,7,9 means no even digits are allowed on that number (12 will not consider). For example, the starting numbers which only contain odd digits are 1,3,5,7,9,11,13,15,17,19,31,33,35 and so on.

Example 1:

Input:
N=3
Output:
5
Explanation:
First three numbers are 1, 3, 5.
Here 5 is the 3rd number, where contains
only odd digits.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long findNumber(long long N)
{
    // Code here
    long digit = 1;
    long result = 0;
    while (N != 0)
    {
        N--;
        result += ((2 * (N % 5)) + 1) * digit;
        N = N / 5;
        digit *= 10;
    }
    return result;
}

int main()
{
    int n = 13;
    cout << findNumber(n);
    return 0;
}