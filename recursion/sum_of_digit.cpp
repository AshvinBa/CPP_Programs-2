#include <iostream>
using namespace std;
int func(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int ans = 0;
    int digit = n % 10;

    ans += digit + func(n / 10);

    return ans;
}
int main()
{
    int n;
    cout << "Entre any digit: ";
    cin >> n;
    cout << func(n);
    return 0;
}