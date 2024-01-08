/*
Find median in a stream

Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:
Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 
 

Example 2:
Input:
N = 3
X[] = 5,10,15
Output:
5
7.5
10
Explanation:Flow in stream : 5, 10, 15
5 goes to stream --> median 5 (5) 
10 goes to stream --> median 7.5 (5,10) 
15 goes to stream --> median 10 (5,10,15) 
Your Task:
You are required to complete the class Solution. 
It should have 2 data members to represent 2 heaps. 
It should have the following member functions:
insertHeap() which takes x as input and inserts it into the heap, the function should then call balanceHeaps() to balance the new heap.
balanceHeaps() does not take any arguments. It is supposed to balance the two heaps.
getMedian() does not take any arguments. It should return the current median of the stream.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
 
Constraints:
1 <= N <= 106
1 <= x <= 106

*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    
    
    void insertHeap(int &x)
    {
        if(maxHeap.size()==0)
        {
            maxHeap.push(x);
            return;
        }
        
        if(maxHeap.size() > minHeap.size())
        {
            if(x < maxHeap.top())
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
            else
            {
                minHeap.push(x);
            }
        }
        else
        {
            if(x<maxHeap.top())
            {
                maxHeap.push(x);
            }
            else
            {
                minHeap.push(x);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxHeap.size()==minHeap.size())
        {
            return (double) (maxHeap.top() + minHeap.top())/2.0;
        }
        
        return maxHeap.top();
    }
};


int main()
{
    int n, x;
    int t;
    cout<<"Enter the nuber of test cases: ";
    cin>>t;
    while(t--)
    {
    	Solution ob;
        cout<<"Enter the size: ";
    	cin >> n;
        cout<<"Enter the values: ";
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}


