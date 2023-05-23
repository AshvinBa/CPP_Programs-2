#include <iostream>
#include<bits/stdc++.h>
using namespace std;

char grtMaxOccurence(string str)
{
    int arr[26] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int number = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else
        {
            number = ch - 'A';
        }
        arr[number]++;
        cout<<arr[number]<<endl;
    }
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
            ans = i;
            maxi = arr[i];
    }
    char maxOccur = 'a' + maxi;
    return maxOccur;
}
int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    cout << "\nMax Occuring Element is: " << grtMaxOccurence(str);
    return 0;
}