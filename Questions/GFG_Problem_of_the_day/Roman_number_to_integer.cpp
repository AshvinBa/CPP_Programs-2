/*
Roman Number to Integer
Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:
Input:
s = V
Output: 5

Example 2:
Input:
s = III 
Output: 3
Your Task:
Complete the function romanToDecimal() which takes a string as input parameter and returns the equivalent decimal number. 

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=roman no range<=3999
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int roman_to_decimal(string str)
{
    unordered_map<char,int>mp;
    mp.insert(make_pair('I',1));
    mp.insert(make_pair('V',5));
    mp.insert(make_pair('X',10));
    mp.insert(make_pair('L',50));
    mp.insert(make_pair('C',100));
    mp.insert(make_pair('D',500));
    mp.insert(make_pair('M',1000));

    int sum=mp[str.back()];

    for(int i=0;i<str.length()-1;i++)
    {
        if(mp[str[i]] < mp[str[i+1]])
        {
            sum-=mp[str[i]];
        }
        else
        {
            sum+=mp[str[i]];
        }
    }
    return sum;
}
int main(){
    string str="X";
    cout<<roman_to_decimal(str); 
return 0;
}