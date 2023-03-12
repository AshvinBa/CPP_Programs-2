#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(vector<vector<int>> vec)
{
    int maxOnes = INT16_MIN;
    int maxOnesRow = -1;
    int column = vec[0].size();

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] == 1)
            {
                int number_of_ones = column - j;
                if (number_of_ones > maxOnes)
                {
                    maxOnes = number_of_ones;
                    maxOnesRow = i;
                }
                break;
            }
        }
    }
    return maxOnesRow;
}
int main()
{
    int n, m;
    cout << "\nEnter the value of Row and Coloum: ";
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m));
    cout << "\nEnter the values: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }
    int result = func(vec);
    cout << "\nThe Row is: " << result << endl;
    return 0;
}

/*approch 2*/

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int func(vector<vector<int>> vec)
// {
//     int maxRow = -1;
//     int j = vec[0].size() - 1;
//     int max_colm = -1;
//     while (j >= 0 and vec[0][j] == 1)
//     {
//         max_colm = j;
//         maxRow = 0;
//         j--;
//     }
//     for (int i = 1; i < vec.size(); i++)
//     {
//         while (j >= 0 and vec[i][j] == 1)
//         {
//             max_colm = j;
//             j--;
//             maxRow = i;
//         }
//     }
//     return maxRow;
// }
// int main()
// {
//     int n, m;
//     cout << "\nEnter the value of Row and Coloum: ";
//     cin >> n >> m;
//     vector<vector<int>> vec(n, vector<int>(m));
//     cout << "\nEnter the values: ";
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> vec[i][j];
//         }
//     }
//     int result = func(vec);
//     cout << "\nThe Row is: " << result << endl;
//     return 0;
// }
