#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    string str1;
    string str2;
    cout << "Enter the str1: ";
    getline(cin, str1);
    cout << "Enter the str2: ";
    getline(cin, str2);

    int len1 = str1.length();
    int len2 = str2.length();

    if (len1 == len2)
    {
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        if (str1 == str2)
        {
            cout << "The following strings are Anagram.";
        }
        else
        {
            cout << "The following string are Not Anagram.";
        }
    }
    return 0;
}