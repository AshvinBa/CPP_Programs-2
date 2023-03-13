/*
Approach 1
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> func(vector<int> v1, vector<int> v2)
{
    vector<int> ans;
    int i = 0, j = 0;
    int n = v1.size();
    int m = v2.size();
    while (i < n and j < m)
    {
        if (v1[i] == v2[j])
        {
            ans.push_back(v1[i]);
            i++;
            j++;
        }
        else if (v1[i] < v2[j])
        {
            i++;
        }
        else if (v1[i] > v2[j])
        {
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> v1{1, 2, 3, 4, 5, 6};
    vector<int> v2{2, 3, 2, 5, 8, 9, 10};
    vector<int> res = func(v1, v2);
    for (auto i = res.begin(); i < res.end(); i++)
    {
        cout << *i << " ";
    }
    return 0;
}

/*
Approach 2
*/

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// vector<int> func(vector<int> v1, vector<int> v2)
// {
//     vector<int> vec;
//     int n = v1.size();
//     int m = v2.size();
//     for (int i = 0; i < n; i++)
//     {
//         int ele = v1[i];

//         for (int j = 0; j < m; j++)
//         {
//             if (ele == v2[j])
//             {
//                 vec.push_back(v2[i]);
//                 v2[i] = -1;
//                 break;
//             }
//         }
//     }
//     return vec;
// }
// int main()
// {
//     vector<int> v1{1, 2, 3, 4, 5};
//     vector<int> v2{1, 2, 3, 14, 15};
//     vector<int> ans = func(v1, v2);
//     for (auto i = ans.begin(); i < ans.end(); i++)
//     {
//         cout << *i << "  ";
//     }
//     return 0;
// }
