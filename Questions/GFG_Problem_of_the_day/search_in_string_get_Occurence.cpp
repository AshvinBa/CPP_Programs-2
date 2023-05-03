// QUESTION: Occurence of the str2 at which Position.

#include <iostream>
using namespace std;

int str(string str1, string str2)
{
    if (str2.empty())
    {
        return -1;
    }
    else
    {
        int found = str1.find(str2);
        if (found != -1)
        {
            return found;
        }
    }
    return -1;
}

int main()
{
    string str1 = "Hello";
    string str2 = "l";
    cout << str(str1, str2);
    return 0;
}