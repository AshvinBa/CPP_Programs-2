/*
You and your books

You have n stacks of books. Each stack of books has some nonzero height arr[i] equal to the number of books on that stack ( considering all the books are identical and each book has a height of 1 unit ). In one move, you can select any number of consecutive stacks of books such that the height of each selected stack of books arr[i] <= k. Once such a sequence of stacks is chosen, You can collect any number of books from the chosen sequence of stacks.
What is the maximum number of books that you can collect this way?

Example 1
Input
8 1
3 2 2 3 1 1 1 3
Output
3
Explanation 
We can collect maximum books from consecutive stacks numbered 5, 6, and 7 having height less than equal to K.

Example 2
Input
8 2
3 2 2 3 1 1 1 3
Output
4
Explanation
We can collect maximum books from consecutive stacks numbered 2 and 3 having height less than equal to K.
Your Task:
You don't have to read input or print anything. Your task is to complete the function max_Books() which takes the integer arr, n, and k returns the maximum number of books you can collect.

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= n <= 105
1 <= k <= 109
1 <= arr[i] <= 109
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;


class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        
        long long maxi=0, sum=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
            {
                sum+=arr[i];
            }
            else
            {
                maxi=max(maxi,sum);
                sum=0;
            }
        }
        maxi=max(maxi,sum);
        return maxi;
    }
};

int main() {
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n, k;
        cout<<"Enter the size and value of K: "; 
        cin >> n >> k;
        int ar[n];
        cout<<"Enter the values: ";
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout<<"Answer: ";
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}