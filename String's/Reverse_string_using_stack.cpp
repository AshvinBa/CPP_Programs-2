/*
Reverse a string using Stack
You are given a string S, the task is to reverse the string using stack.

Example 1:
Input: S="GeeksforGeeks"
Output: skeeGrofskeeG
*/

#include <bits/stdc++.h>
using namespace std;
char *reverse(char *str, int len);
int main()
{
    cout << "Enter the string: ";
    char str[10000];
    cin >> str;
    long long int len = strlen(str);
    char *ch = reverse(str, len);
    for (int i = 0; i < len; i++)
    {
        cout << ch[i];
    }
    cout << endl;

return 0;
}

char *reverse(char *S, int len)
{
    stack<char> st;
    for (int i = 0; i < len; i++)
    {
        st.push(S[i]);
    }
    char *a = new char[len];
    int i = 0;
    while (!st.empty())
    {
        a[i++] = st.top();
        st.pop();
    }
    a[i] = '\0';
    return a;
}