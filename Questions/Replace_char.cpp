#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cout << "Enter the line: ";
    getline(cin, str);
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && 'Z' >= str[i])
        {
            str[i] = '*';
        }
        else if (str[i] >= 'a' && 'z' >= str[i])
        {
            str[i] = '#';
        }
    }
    cout << str;
    return 0;
}