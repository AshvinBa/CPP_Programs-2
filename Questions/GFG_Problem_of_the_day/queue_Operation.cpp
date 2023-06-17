#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    unordered_map<int,int>mp;

    void insert(queue<int> &q, int k)
    {
        q.push(k);
        mp[k++];
    }
    
    int findFrequency(queue<int> &q, int k)
    {  
        return mp[k];
        // if(mp[k]>=1)
        // {
        //     return mp[k];
        // }
        // else
        // {
        //     return 0;
        // }
    }
    
};

//{ Driver Code Starts.
int main() {
    
		int testcase;
        cout<<"Enter the values of test cases: ";
		cin>>testcase;
		
		while(testcase-- > 0){
		    // Declaring Queue
		    queue<int> q;
		    int n, k;
            cout<<"Enter the limit of first array: ";
		    cin>>n;
		    
		    // Invoking object of Geeks class
		    Solution obj;
		    cout<<"Enter the values of the array: ";
		    for(int i = 0;i<n;i++){
		        cin >> k;
		        obj.insert(q, k);
		    }
		   
		    int m;
            cout<<"Enter the limit of second array: ";
		    cin >> m;
            cout<<"Enter the values of the array: ";
		    for(int i = 0;i<m;i++){
		        cin >> k;
		        int f = obj.findFrequency(q, k);
		        if(f != 0){
		            cout<<f<<endl;
		        }
		        else{
		            cout<<"-1\n";
		        }
		    }
		}
	return 0;
}