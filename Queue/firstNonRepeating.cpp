#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string nonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<int> q;
    string str = "";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        count[ch]++;

        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                str.push_back(q.front());
                break;
            }
        }
        if (q.empty())
            str.push_back('#');
    }
    return str;
}

int main()
{
    string A = "aabc";
    cout << nonRepeating(A);
    return 0;
}
