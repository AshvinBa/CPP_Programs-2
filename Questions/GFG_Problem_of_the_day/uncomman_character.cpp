/*
Uncommon characters

Given two strings A and B. Find the characters that are not common in the two strings. 
Note :- Return the string in sorted order.

Example 1:
Input:
A = geeksforgeeks
B = geeksquiz
Output: fioqruz
Explanation: 
The characters 'f', 'i', 'o', 'q', 'r', 'u','z' 
are either present in A or B, but not in both.

Example 2:
Input:
A = characters
B = alphabets
Output: bclpr
Explanation: The characters 'b','c','l','p','r' 
are either present in A or B, but not in both.
*/

#include <iostream>
using namespace std;

string UncommonChars(string A, string B)
{
    int s1[26] = {0}, s2[26] = {0};

    for (int i = 0; i < A.size(); i++)
    {
        s1[A[i] - 'a']++;
    }

    for (int i = 0; i < B.size(); i++)
    {
        s2[B[i] - 'a']++;
    }

    string ans = "";
    for (int i = 0; i < 26; i++)
    {
        if (s1[i] >= 1 && s2[i] == 0 || s1[i] == 0 && s2[i] >= 1)
        {
            ans += char(i + 'a');
        }
    }
    if (ans.size() > 0)
    {
        return ans;
    }
    else
    {
        ans = "-1";
        return ans;
    }
}
int main()
{
    string str1 = "geeksforgeeks";
    string str2 = "geeksquiz";
    cout<<"\nThe Uncomman characters are: "<<UncommonChars(str1,str2);

    return 0;
}