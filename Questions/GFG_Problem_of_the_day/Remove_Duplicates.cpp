/*
Remove Duplicates

Given a string str without spaces, the task is to remove all duplicate characters from it, keeping only the first occurrence.

Note: The original order of characters must be kept the same.

Examples :
Input: str = "zvvo"
Output: "zvo"
Explanation: Only keep the first occurrence

Input: str = "gfg"
Output: "gf"
Explanation: Only keep the first occurrence

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= |str| <= 105
str contains lowercase English alphabets
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeDups1(string str)
    {

        vector<bool> seen(26, false); // to keep track of seen characters
        string result = "";

        for (char ch : str)
        {
            if (!seen[ch - 'a'])
            {
                seen[ch - 'a'] = true;
                result += ch;
            }
        }

        return result;
    }

    string removeDups2(string str) {
    
    int arr[26]={0};
    int j=0;
    
    for(int i=0;i<str.length();i++)
    {
        if(arr[str[i]-'a']==0)
        {
            str[j++]=str[i];
        }
        arr[str[i]-'a']=1;
    }
    return str.substr(0,j);
    }

};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups1(s) << "\n";
        cout << ob.removeDups2(s) << "\n";
    }

    return 0;
}