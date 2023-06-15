/*
Longest Palindrome in a String

Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string that reads the same backward. More formally, S is a palindrome if reverse(S) = S. In case of conflict, return the substring which occurs first ( with the least starting index).

Example 1:
Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".

Example 2:
Input:
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the
longest palindromes with same length.
The result is the one with the least
starting index.

*/

#include <iostream>
using namespace std;

string longestPalin(string S)
{

    int start = 0, end = 0, len = 0, n = S.length();

    for (int i = 1; i < n; i++)
    {
        int s = i - 1, e = i + 1;

        while (s >= 0 and e < n and S[s] == S[e])
        {
            if (e - s + 1 > len)
            {
                len = e - s + 1;
                start = s;
                end = e;
            }
            s--;
            e++;
        }

        s = i - 1;
        e = i;

        while (s >= 0 and e < n and S[s] == S[e])
        {
            if (e - s + 1 > len)
            {
                len = e - s + 1;
                start = s;
                end = e;
            }
            s--;
            e++;
        }
    }
    string str = "";

    for (int i = start; i <= end; i++)
    {
        str += S[i];
    }

    return str;
}

int main()
{
    string S = "a5bababa";
    cout<<"\nThe Longest Palindrom is: "<<longestPalin(S);
    return 0;
}