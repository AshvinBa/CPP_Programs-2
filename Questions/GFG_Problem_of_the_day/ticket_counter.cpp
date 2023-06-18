/*

Ticket Counter

N people from 1 to N are standing in the queue at a movie ticket counter. It is a weird counter, as it distributes tickets to the first K people and then the last K people and again first K people and so on, once a person gets a ticket moves out of the queue. The task is to find the last person to get the ticket.

Example 1
Input:
N = 9
K = 3
Output: 6
Explanation:
Starting queue will like {1, 2, 3, 4, 5, 6, 7, 8, 9}. After the first distribution queue will look like {4, 5, 6, 7, 8, 9}. And after the second distribution queue will look like {4, 5, 6}. The last person to get the ticket will be 6.


Example 2
Input:
N = 5
K = 1
Output: 3
Explanation:
Queue start as {1, 2, 3, 4, 5} -> {2, 3, 4, 5} -> {2, 3, 4} -> {3, 4} -> {3}
Last person to get ticket will be 3.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
Try to solve it using O(1) space complexity.

*/

#include<iostream>
using namespace std;

int ticket(int n,int k)
{
    int i=1;
    int j=n;
    bool a=false;
    int ans;
    while(i<=j)
    {
        if(!a)
        {
            i+=k;
            ans=j;
        }
        else
        {
            j-=k;
            ans=i;
        }
        a=!a;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the value of N: ";
    cin>>n;
    int k;
    cout<<"Enter the value of K: ";
    cin>>k;
    cout<<"\nThe last Ticket are going to: "<<ticket(n,k);
return 0;
}