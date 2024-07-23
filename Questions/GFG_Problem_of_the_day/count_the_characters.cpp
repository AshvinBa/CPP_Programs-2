/*
Count the characters
Given a string S. Count the characters that have ‘N’ number of occurrences. If a character appears consecutively it is counted as 1 occurrence.

Example 1:

Input:
S = "abc", N = 1
Output: 3
Explanation: 'a', 'b' and 'c' all have 
1 occurrence.

Example 2:

Input: 
S = "geeksforgeeks", N = 2
Output: 4
Explanation: 'g', 'e', 'k' and 's' have
2 occurrences.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getCount() which takes the string S and an integer N as inputs and returns the count of the characters that have exactly N occurrences in the string. Note that the consecutive occurrences of a character have to be counted as 1.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1<=|S|<=105
1<=N<=103
*/


#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
        int getCount (string S, int N)
        {
            unordered_map<char, int> charCount;
            int length = S.length();

            // Count non-consecutive occurrences
            for (int i = 0; i < length; ++i) {
            if (i == 0 || S[i] != S[i - 1]) {
            charCount[S[i]]++;
            }
        }

        // Count how many characters have exactly N occurrences
        int result = 0;
        for (const auto& entry : charCount) {
        if (entry.second == N) {
            result++;
        }
    }
    return result;
        }
};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n; cin >> n;
        
        Solution ob;
        cout <<ob.getCount (s, n) << endl;
    }
}
