/*
Reversing the equation

Given a mathematical equation that contains only numbers and +, -, *, /. Print the equation in reverse, such that the equation is reversed, but the numbers remain the same.
It is guaranteed that the given equation is valid, and there are no leading zeros.

Example 1:
Input:
S = "20-3+5*2"
Output: 2*5+3-20
Explanation: The equation is reversed with
numbers remaining the same.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string reverseEqn(string s)
{
    int n = s.length();
    reverse(s.begin(), s.end());

    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
        {
            int j = i - 1;
            while (prev < j)
            {

                swap(s[prev], s[j]);
                prev++;
                j--;
            }
            prev = i + 1;
        }
    }
    int j = n - 1;
    while (prev < j)
    {
        swap(s[prev], s[j]);
        prev++;
        j--;
    }
    return s;
}

int main()
{
    string s = "20+3-9*78";
    cout << reverseEqn(s);
    return 0;
}