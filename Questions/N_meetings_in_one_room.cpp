/*
N meetings in one room

There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i]
is start time of meeting i and end[i] is finish time of meeting i.What is the maximum number of meetings 
that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Example 1:
Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)

Example 2:
Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 
1
Explanation:
Only one meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function maxMeetings() that takes two arrays start[] and end[]
along with their size N as input parameters and returns the maximum number of meetings that can be held in the meeting room.

Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)

Constraints:
1 ≤ N ≤ 105
0 ≤ start[i] < end[i] ≤ 105
*/


#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    static bool comp(pair<int,int>a , pair<int,int>b)
    {
        if(a.second == b.second)
        return a.first < b.first;
        
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v(n);
        
        for(int i=0;i<n;i++)
        v[i]={start[i],end[i]};
        
        sort(v.begin(),v.end(),comp);
        
        int i=0;
        int j=1;
        int c=1;
        
        while(j<n)
        {
            if(v[i].second < v[j].first)
            {
                c++;
                i=j;
                j++;
            }
            else
            {
                j++;
            }
        }
        return c;
    }
};

int main() {
    int t;
    cout<<"Enter the nuber of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout<<"Enter the value of N: ";
        cin >> n;
        int start[n], end[n];
        cout<<"Enter the values of start: ";
        for (int i = 0; i < n; i++) cin >> start[i];

        cout<<"Enter the values of end: ";
        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout<<"Answer: ";
        cout << ans << endl;
    }
    return 0;
}