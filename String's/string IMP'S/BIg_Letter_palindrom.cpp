#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char to_lowercase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool Palindrom(char str[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        if (to_lowercase(str[s++]) != to_lowercase(str[e--]))
            return false;
        else
            return true;
    }
}
int size(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char str[20];
    cout << "Enter the string: ";
    cin >> str;
    char ch='a';

    int n = size(str);
    bool x = Palindrom(str, n);
    if (x)
    {
        cout << "Yes!,...Palindrom.";
    }
    else
    {
        cout << "Not!,...Not Palindrom";
    }
    return 0;
}
