/*
POTD

Date - 16-04-2023.

Problem-

Input:
N = 3
A[] = {2, 5, 6}
B[] = {1, 2, 10}
Output: 2
Explanation: 
Select i = 3, j = 2, A[3] = 6 + 2 = 8 and A[2] = 5 - 2 = 3
Select i = 3, j = 2, A[3] = 8 + 2 = 10 and A[2] = 3 - 2 = 1
Now A = {2, 1, 10} and B = {1, 2, 10}

*/

// Solution ->

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long uneque(vector<int> A, vector<int> B, int n)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> Aodds, Aeven, Bodds, Beven;
    long long sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        sum1 += A[i];
        sum2 += B[i];

        if (A[i] % 2 != 0)
            Aodds.push_back(A[i]);
        else
            Aeven.push_back(A[i]);

        if (B[i] % 2 != 0)
            Bodds.push_back(B[i]);
        else
            Beven.push_back(B[i]);
    }

    if (sum1 != sum2 || Aodds.size() != Bodds.size())
        return -1;

    long long ans = 0;

    for (int i = 0; i < Aodds.size(); i++)
    {
        ans += abs(Aodds[i] - Bodds[i]);
    }
    for (int i = 0; i < Aeven.size(); i++)
    {
        ans += abs(Aeven[i] - Beven[i]);
    }

    return ans / 4;
}

int main()
{
    vector<int> A{3, 3};
    vector<int> B{8, 10};
    int n = A.size();
    cout << "\nAnswer: " << uneque(A, B, n);
    return 0;
}