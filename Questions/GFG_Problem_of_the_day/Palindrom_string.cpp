/*
Palindrome String
Given a string S, check if it is palindrome or not.

Example 1:
Input: S = "abba"
Output: 1
Explanation: S is a palindrome

Example 2:
Input: S = "abc"
Output: 0
Explanation: S is not a palindrome

*/
#include <iostream>
using namespace std;
int isPalindrome(string S)
{
    int i = 0;
    int j = S.length() - 1;
    while (i < j)
    {
        if (S[i] != S[j])
        {
            return 0;
        }
        else
        {
            i++;
            j--;
        }
    }
    return 1;
}

int main()
{
    string S = "abba";
    if (isPalindrome(S))
    {
        cout << "Yes,It's Palindrom.";
    }
    else
    {
        cout << "No,It's Not a Palindrom.";
    }
    return 0;
}
