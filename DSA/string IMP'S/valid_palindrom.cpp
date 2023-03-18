#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool valid(char ch)
{
    if ((ch > 'a' && ch < 'z') || (ch > 'A' && ch < 'Z') || (ch > 1 && ch < 9))  /*for valid char*/
    {
        return true;
    }
    else
    {
        return false;
    }
}

char check_lowercase(char ch)  /*convert into lowercase*/
{
    if (ch > 'A' && ch < 'Z')
    {
        char T = ch - 'A' + 'a';
        return T;
    }
    else
    {
        return ch;
    }
}

bool Check_Palindrom(string temp)  /*To check palindrom*/
{
    int s = 0;
    int e = temp.length() - 1;

    while (s <= e)
    {
        if (temp[s++] != temp[e--])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

bool isPalindrom(string s)
{
    string temp = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (valid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }

    for (int j = 0; j < temp.length(); j++)   /*Remove all invalid character*/
    {
        temp[j] = check_lowercase(temp[j]);
    }
    return Check_Palindrom(temp);
}
int main()
{
    char name[200];
    cout << "Enter the name: ";
    cin >> name;
    bool x = isPalindrom(name);
    if (x)
    {
        cout << "YES...Palindrom.";
    }
    else
    {
        cout << "NOT...NOT Palindrom.";
    }
    return 0;
}