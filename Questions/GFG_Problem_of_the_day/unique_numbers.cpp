/*
Unique Numbers

In the given range [L, R], print all numbers having unique digits. e.g. In range 10 to 20 should print all numbers except 11.

Example 1:

Input:
L = 10
R = 20

Output:
10 12 13 14 15 16 17 18 19 20

Explanation:
The number 11 has two 1 therefore
11 is not a unique number.
Example 2:

Input:
L = 1
R = 9

Output:
1 2 3 4 5 6 7 8 9

Explanation:
All the Numbers are unique.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function uniqueNumbers() which takes two integers L and R as an input parameter and returns the list/vector of all the unique numbers present between L to R.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= L <= R <= 104
*/

#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:

    bool hasUniqueDigits(int num) {
    unordered_set<int> digits;
    while (num > 0) {
        int digit = num % 10;
        if (digits.find(digit) != digits.end()) {
            return false;
        }
        digits.insert(digit);
        num /= 10;
    }
    return true; 
    }
    
    vector<int> uniqueNumbers(int L,int R)
    {
        vector<int> ans;
        for (int i = L; i <= R; i++) {
        if (hasUniqueDigits(i)) {
            ans.push_back(i);
        }
    }
    return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l,r ;
        cin >> l >> r;
		Solution ob;
		vector<int> numbers = ob.uniqueNumbers(l,r);
		
		for(int num : numbers){
		   cout<<num<<" ";
		}
		cout<<endl;
        
    }
    return 0;
}