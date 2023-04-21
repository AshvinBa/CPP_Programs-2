#include <iostream>
using namespace std;

bool wifiRange(int N, string S, int X)
{
    int freq[N + 1] = {0};
    for (int i = 0; i < N; i++)
    {
        if (S[i] == '1')
        {
            int left = max(i - X, 0);
            int right = min(i + X, N - 1);
            freq[left]++;
            freq[right + 1]--;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            freq[i] += freq[i - 1];

        if (freq[i] == 0)
            return false;
    }
    return true;
}

int main()
{
    string S = "10000001";
    int N = S.length();
    int X = 4;
    bool x1 = wifiRange(N, S, X);
    if (x1)
    {
        cout << "Yes.";
    }
    else
    {
        cout << "No.";
    }
    return 0;
}