// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// int func(vector<int> &vec, int n)
// {
//     int i = 0, j = n - 1;
//     while (i < j)
//     {
//         if(vec[i] == 0)
//         {
//             i++;
//         }
//         else if(vec[j] ==1)
//         {
//             j--;
//         }
//         else if (vec[i] == 1 and vec[j] == 0)
//         {
//             vec[i++] = 0;
//             vec[j--] = 1;
//         }
//     }
// }
// int main()
// {
//     vector<int> vec{0, 0, 1, 1, 0, 1};
//     int n = vec.size();
//     func(vec, n);
//     cout << "Array is: ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << vec[i] << " ";
//     }
//     return 0;
// }



#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int func(vector<int> &vec, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if(vec[i] == 0)
        {
            i++;
        }
        else if(vec[j] ==1)
        {
            j--;
        }
        else if (vec[i] == 1 and vec[j] == 0)
        {
            swap(vec[i],vec[j]);
        }
    }
}
int main()
{
    vector<int> vec{0, 0, 1, 1, 0, 1};
    int n = vec.size();
    func(vec, n);
    cout << "Array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}

















