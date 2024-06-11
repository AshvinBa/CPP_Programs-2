/*
Nuts and Bolts Problem

Given a set of n nuts & bolts. There is a one-on-one mapping between nuts and bolts. You have to Match nuts and bolts efficiently. Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means the nut can only be compared with the bolt and the bolt can only be compared with the nut to see which one is bigger/smaller.
The elements should follow the following order: { !,#,$,%,&,*,?,@,^ }

Note: Make all the required changes directly in the given arrays, output will be handled by the driver code.

Examples

Input: n = 5, nuts[] = {@, %, $, #, ^}, bolts[] = {%, @, #, $ ^}
Output: 
# $ % @ ^
# $ % @ ^
Explanation: As per the order # should come first after that $ then % then @ and ^. 

Input: n = 9, nuts[] = {^, &, %, @, #, *, $, ?, !}, bolts[] = {?, #, @, %, &, *, $ ,^, !}
Output: 
! # $ % & * ? @ ^
! # $ % & * ? @ ^
Explanation: We'll have to match first ! then  # , $,  %,  &,  *,  @,  ^,  ? as per the required ordering.
Expected Time Complexity: O(n(logn))
Expected Auxiliary Space: O(log(n))

Constraints:
1 <= n <= 9
The arrays 'nuts' and 'bolts' can only consist of the following elements: {'@', '#', '$', '%', '^', '&', '?', '*', '!'}.
All the elements of arrays 'nuts' and 'bolts' should be unique.
*/


    /* Approach - 1. */
    // void matchPairs(int n, char nuts[], char bolts[]) 
    // {
    //     sort(nuts,nuts+n);
    //     sort(bolts,bolts+n);       
    // }

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

  int quickSort(char arr[],int s,int e)
    {
        int pivot = arr[s];
        
        int cnt=0;
        
        for(int i=s+1;i<=e;i++)
        {
            if(arr[i]<=pivot)
            {
                cnt++;
            }
        }
        
        int pivotIndex = s+cnt;
        
        swap(arr[pivotIndex],arr[s]);
        
        int i=s,j=e;
        
        
        while( i < pivotIndex && j > pivotIndex )
        {
            while(arr[i]<=pivot)
            {
                i++;
            }
            while(arr[j]>=pivot)
            {
                j--;
            }
            if(i<pivotIndex && j>pivotIndex)
            {
                swap(arr[i++],arr[j--]);
            }
        }
        return pivotIndex;
    }
  
    void partition(char arr[],int s,int e)
    {
        if(s>=e)
        return;
        
        int p=quickSort(arr,s,e);
        
        partition(arr,s,p-1);
        partition(arr,p+1,e);
    }

    
    void matchPairs(int n, char nuts[], char bolts[]) {
        
        partition(nuts,0,n-1);
        partition(bolts,0,n-1);
        
    }


};

int main() {
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout<<"Entre the size of the nuts and bolts: ";
        cin >> n;
        char nuts[n], bolts[n];
        cout<<"Enter the values: ";
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        cout<<"Enter the values: ";
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        cout<<"Solution of the nuts and bolts: ";
        ob.matchPairs(n, nuts, bolts);
        cout<<"\n";
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
