#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool Palindrom(char str[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        if(str[s++]!=str[e--])
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
    int n = size(str);
    bool x=Palindrom(str, n);
    if(x)
    {
        cout<<"Yes!,...Palindrom.";
    }
    else
    {
        cout<<"Not!,...Not Palindrom";
    }
    return 0;
}



/*
Enter the string: noon
Yes!,...Palindrom.

Enter the string: Noon
Not!,...Not Palindrom
*/