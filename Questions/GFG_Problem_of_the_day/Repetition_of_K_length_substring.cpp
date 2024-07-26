/*
Repetition of k length substring

Given a string 's', your task is to complete the function checkString which returns true if it is possible to convert 's' to a string that is repetition of a substring with 'k' characters else returns false, where in order to convert we can replace one substring of length k with k characters.
 

Examples:

Input: str = "abcbedabcabc",  k = 3
Output: 1
Replace "bed" with "abc" so that the 
whole string becomes repetition of "abc".

Input: str = "bcacbcac", k = 2
Output: 0

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 2 lines. The first line of each test case contains a string s. The second line of each test case contains an integer n.

Output:
For each test case in a new line output will be 1 if it is possible to convert the string else 0.

Constraints:
1<=T<=100
1< |Length of string| <=100
1<=N<=10

Example(To be used only for expected output):
Input:
2
abcbedabcabc
3
bcacbcac
2
Output:
1
0
*/


#include<bits/stdc++.h>
using namespace std;
 
bool checkString(string str, int k);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		string s;
		cin>>s;
		int k;
		cin>>k;
      cout<<checkString(s, k)<<endl;
	}
    return 0;
}

/*You are required to complete below method */
bool checkString(string str, int k)
{
    int n = str.length();
    
    if (n % k != 0) {
        return 0;
    }

    unordered_map<string, int> mp;
    for (int i = 0; i < n; i += k) {
        mp[str.substr(i, k)]++;
    }

    if (mp.size() > 2) {
        return 0;
    }

    if (mp.size() == 1) {
        return 1;
    }

    // If there are exactly 2 different substrings
    auto it = mp.begin();
    string s1 = it->first;
    int count1 = it->second;
    it++;
    string s2 = it->first;
    int count2 = it->second;

    // We can replace one substring of length k with another substring of length k
    if (count1 == 1 || count2 == 1) {
        return 1;
    }

    return 0;
}