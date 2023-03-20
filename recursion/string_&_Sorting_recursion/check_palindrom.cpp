#include <iostream>
using namespace std;
bool func(string str, int n, int i, int j)
{
    if (i > j)
        return true;

    if (str[i] != str[j])
    {
        return false;
    }
    else
    {
        return func(str, n, i + 1, j - 1);
    }
}
int main()
{
    string str = "an546ana";
    int n = str.length();
    bool x = func(str, n, 0, n - 1);
    if (x == 1)
    {
        cout << "Palindrom.";
    }
    else
    {
        cout << "Not Palindrom.";
    }
    return 0;
}