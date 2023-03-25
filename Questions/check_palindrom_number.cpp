#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the nuber to check palindrom: ";
    cin >> n;
    int t = n;
    int ans = 0;
    while (t != 0)
    {
        int digit = t % 10;
        ans = ans * 10 + digit;
        t = t / 10;
    }
    if (ans == n)
    {
        cout << "Yes its palindrom.";
    }
    else
    {
        cout << "Its not palindrom.";
    }
    return 0;
}