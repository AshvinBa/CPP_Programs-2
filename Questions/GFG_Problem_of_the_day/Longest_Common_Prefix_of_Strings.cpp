/*
Longest Common Prefix of Strings

Given an array of strings arr. Return the longest common prefix among all strings present in the array. If there's no prefix common in all the strings, return "-1".

Examples :
Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
Output: gee
Explanation: "gee" is the longest common prefix in all the given strings.

Input: arr[] = ["hello", "world"]
Output: -1
Explanation: There's no common prefix in the given strings.

Expected Time Complexity: O(n*min(|arri|))
Expected Space Complexity: O(min(|arri|))

Constraints:
1 ≤ |arr| ≤ 103
1 ≤ |arr[i]| ≤ 103

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> str)
    {
        int small = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i].length() < arr[small].length())
            {
                small = i;
            }
        }

        string temp = arr[small];
        int i = 0, j = 0;

        while (i < temp.length())
        {
            for (j = 0; j < arr.size(); j++)
            {
                if (temp[i] != arr[j][i])
                    break;
            }
            if (j != arr.size())
                break;
            i++;
        }
        if (i == 0)
            return "-1";

        return temp.substr(0, i);
    }
};

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<string> arr;
        string input;
        cout << "Enter the string: ";
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        cout << "Answer: ";
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}
