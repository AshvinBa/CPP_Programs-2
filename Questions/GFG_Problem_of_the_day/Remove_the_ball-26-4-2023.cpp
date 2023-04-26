/*
Remove the balls

Imagine an imaginary array of length N containing balls. Given 2 arrays color and radius of length N each, where color[i] represents the color of the ith ball while radius[i] represents the radius of ith ball. If two consecutive balls have the same color and size, both are removed from the array. Geek wants to know the length of the final imaginary array.

Example 1:

Input:
N = 3
color[] = {2, 2, 5}
radius[] = {3, 3, 4}
Output: 
1
Explanation: 
First ball and second ball have same color 2 and 
same radius 3.So,after removing only one ball 
is left.It could not be removed from the array. 
Hence, the final array has length 1.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findLen(int N, int color[], int radius[])
{
    stack<int> st;

    for (int i = 0; i < N; i++)
    {
        if (!st.empty())
        {
            int prev = st.top();
            if (color[prev] == color[i] && radius[prev] == radius[i])
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
        else
        {
            st.push(i);
        }
    }
    return st.size();
}

int main()
{
    int n = 3;
    int color[] = {2, 2, 5};
    int radius[] = {3, 3, 4};
    cout << "Answer: " << findLen(n, color, radius);

    return 0;
}