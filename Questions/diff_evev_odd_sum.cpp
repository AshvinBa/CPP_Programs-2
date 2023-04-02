#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the Digit: ";
    cin >> n;
    int T = n;

    int last = 0;
    int ans = 0;
    while (T != 0)
    {
        last = T % 10;
        if (last % 2 == 0)
        {
            ans += last;
        }
        else
        {
            ans -= last;
        }
        T = T / 10;
    }
    if (ans > 0)
    {
        cout << "The Difference is: " << ans;
    }
    else
    {
        cout << "Difference is less than 0.";
    }
    return 0;
}