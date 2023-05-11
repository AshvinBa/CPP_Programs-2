/*

Palindrome with minimum sum

Given a string, S.The string can contain small case English letters or '?'. You can replace '?' with any small English letter. Now if it is possible to make the string S a palindrome after replacing all '?' then find the palindromic string with a minimum ascii sum of the absolute difference of adjacent characters. Otherwise, return -1.

Example 1:

Input: S = a???c??c????
Output: 4
Explanation:
We can see that we can make the string
palindrome. Now to get minimum ascii sum we should
replace all the '?' between 'a' and 'c' with
'b' and all the '?' between two 'c' with 'c'.
So after replacing all the '?' the string:
abbbccccbbba.
The sum of differences of adjacent characters is 4.


Example 2:
Input: S = a???c??c???c
Output: -1
Explanation:
It is not possible to make the string palindrome.

*/

#include <iostream>
using namespace std;

char check(string s)
{
    int i = 0, j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != '?')
            return s[i];
        if (s[j] != '?')
            return s[j];

        i++;
        j--;
    }
    return '*';
}

int minimumSum(string s)
{
    // code here
    int i = 0, j = s.length() - 1, ans = 0;
    char prev = '*';
    while (i <= j)
    {
        if (s[i] == '?' and s[j] == '?')
        {
            if (prev == '*')
            {
                prev = check(s);
                if (prev == '*')
                    return 0;
            }
        }
        else if (s[i] == '?')
        {
            if (prev != '*')
            {
                ans += 2 * abs(prev - s[j]);
            }
            prev = s[j];
        }
        else if (s[j] == '?')
        {
            if (prev != '*')
            {
                ans += 2 * abs(prev - s[i]);
            }
            prev = s[i];
        }
        else if (s[i] == s[j])
        {
            if (prev != '*')
            {
                ans += 2 * abs(prev - s[i]);
            }
            prev = s[i];
        }
        else
            return -1;

        i++;
        j--;
    }
    return ans;
}

int main()
{
    string str = "a???c??c????";
    cout << "Answer: " << minimumSum(str);
    return 0;
}