/*
Check if string is rotated by two places
Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating (in any direction) string 'a' by exactly 2 places.

Example 1:
Input:
a = amazon
b = azonam
Output: 
1
Explanation: 
amazon can be rotated anti-clockwise by two places, which will make it as azonam.

Example 2:
Input:
a = geeksforgeeks
b = geeksgeeksfor
Output: 
0
Explanation: 
If we rotate geeksforgeeks by two place in any direction, we won't get geeksgeeksfor.
Your Task:
The task is to complete the function isRotated() which takes two strings as input parameters and checks if given strings can be formed by rotations. The function returns true if string 1 can be obtained by rotating string 2 by two places, else it returns false.

Expected Time Complexity: O(N).
Expected Auxilary Complexity: O(N).
Challenge: Try doing it in O(1) space complexity.

Constraints:
1 ≤ length of a, b ≤ 105

*/

#include<iostream>
using namespace std;

bool isRotated(string s1,string s2)
{
    int n=s1.length();
    if(n==2)
    return s1==s2;

    for(int i=0;i<n;i++)
    {
        if(s1[(i+2)%n]==s2[i] || s1[(n+i-2)%n]==s2[i])
        continue;
        else
        return false;
    }
    return true;
}

int main(){

    string s1="amazon";
    string s2="azonam";
    if(isRotated(s1,s2))
    {
        cout<<"Yes its rotated from two side.";
    }
    else
    {
        cout<<"No its not rotated from two side.";
    }
    
return 0;
}