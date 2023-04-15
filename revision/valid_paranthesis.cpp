#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool paranthesis(string str)
{
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {

            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if(s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string str = "(())";
    bool x=paranthesis(str);
    if(x==true)
    {
        cout<<"Not present.";
    }
    else
    {
        cout<<"Yes Present.";
    }
    return 0;
}