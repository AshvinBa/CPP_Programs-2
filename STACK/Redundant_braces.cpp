#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool findRedundant(string &str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isRedundant = true;

                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '*' || top == '-' || top == '/' || top == '+')
                    {
                        isRedundant = false;
                    }
                    s.pop();
                }

                if (isRedundant == true)
                {
                    return true;
                    s.pop();
                }
            }
        }
    }
    return false;
}
int main()
{
    string str = "(((5+2)+3)-8)";
    bool x = findRedundant(str);
    if (x)
    {
        cout << "It's Redundant.";
    }
    else
    {
        cout << "It's Not Redundant.";
    }
    return 0;
}