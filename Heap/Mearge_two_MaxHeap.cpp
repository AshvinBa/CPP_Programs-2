/*
Merge two binary Max heaps
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

Example 1:
Input  :
n = 4 m = 3
a[] = {10, 5, 6, 2},
b[] = {12, 7, 9}
Output :
{12, 10, 9, 2, 5, 7, 6}
Explanation :

Your Task:
You don't need to read input or print anything. Your task is to complete the function mergeHeaps() which takes the array a[], b[], its size n and m, as inputs and return the merged max heap. Since there can be multiple solutions, therefore, to check for the correctness of your solution, your answer will be checked by the driver code and will return 1 if it is correct, else it returns 0.

Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(n + m)

Constraints:
1 <= n, m <= 105
1 <= a[i], b[i] <= 2*105

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void heapify(vector<int> &arr, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;     //for 0 base indexing
        int right = 2 * i + 2;

        if (left < n && arr[largest] < arr[left])
        {
            largest = left;
        }

        if (right < n && arr[largest] < arr[right])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        vector<int> ans;

        for (auto i : a)
            ans.push_back(i);

        for (auto i : b)
            ans.push_back(i);

        int size = ans.size();
        for (int i = size / 2 - 1; i >= 0; i--)     // for zero based indexing
        {
            heapify(ans, size, i);
        }
        return ans;
    }
};

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged)
{
    if (arr1.size() + arr2.size() != merged.size())
    {
        return false;
    }
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    sort(arr1.begin(), arr1.end());
    vector<int> mergedCopy = merged;
    sort(mergedCopy.begin(), mergedCopy.end());
    if (arr1 != mergedCopy)
    {
        return false;
    }
    for (int i = 1; i < merged.size(); i++)
    {
        if (merged[i] > merged[(i - 1) / 2])
            return false;
    }
    return true;
}
int main()
{
    int t;
    cout<<"Enter the Test cases: ";
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cout<<"Enter the size of array 1 and array 2: ";
        cin >> n >> m;
        vector<int> a(n, 0), b(m, 0);
        cout<<"Enter the values: ";
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout<<"Enter the values: ";
        for (i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if (flag == false)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
