#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void erase(string &S, vector<string> &ans, unordered_map<string, int> &mm)
{
    int i = 0, j = S.length() - 1;

    for (i = S.length() - 2; i >= 0; i--)
    {
        if (S[i] < S[i + 1])
            break;
    }
    if (i < 0)
        return;

    for (int k = S.length() - 1; k > i; k--)
    {
        if (S[k] > S[i])
        {
            j = k;
            break;
        }
    }
    swap(S[i], S[j]);
    i++;
    j = S.length() - 1;

    while (i < j)
    {
        swap(S[i], S[j]);
        i++;
        j--;
    }
    mm[S]++;

    if (mm[S] == 1)
        ans.push_back(S);
}

vector<string> find_permutation(string &S)
{
    sort(S.begin(), S.end());
    vector<string> ans;
    ans.push_back(S);

    unordered_map<string, int> mm;
    mm[S]++;
    int fact = 1;

    for (int i = 2; i <= S.length(); i++)
        fact *= i;
    fact--;

    while (fact--)
    {
        erase(S, ans, mm);
    }
    return ans;
}

int main()
{
    string s = "ABC";
    vector<string> sr = find_permutation(s);
    cout<<"The Permutation is: ";
    for(auto i:sr)
    {
        cout<<i<<" ";        
    }
    return 0;
}