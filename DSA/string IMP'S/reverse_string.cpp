#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void reverse(char str[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        swap(str[s], str[e]);
        s++;
        e--;
    }
    cout << str;
}
int size(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char str[20];
    cout << "Enter the string: ";
    cin >> str;
    int n = size(str);
    reverse(str, n);
    return 0;
}