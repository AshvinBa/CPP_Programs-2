/*

Phone directory
HardAccuracy: 25.68%Submissions: 39K+Points: 8
30+ People have Claimed their 90% Refunds. Start Your Journey Today! 

banner
Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".

Example 1:

Input: 
n = 3
contact[] = {"geeikistest", "geeksforgeeks", 
"geeksfortest"}
s = "geeips"
Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
Explaination: By running the search query on 
contact list for "g" we get: "geeikistest", 
"geeksforgeeks" and "geeksfortest".
By running the search query on contact list 
for "ge" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "gee" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "geei" we get: "geeikistest".
No results found for "geeip", so print "0". 
No results found for "geeips", so print "0".
Your Task:
You do not need to read input or print anything. Your task is to complete the function displayContacts() which takes n, contact[ ] and s as input parameters and returns a list of list of strings for required prefixes. If some prefix has no matching contact return "0" on that list.

Expected Time Complexity: O(|s| * n * max|contact[i]|)
Expected Auxiliary Space: O(n * max|contact[i]|)

Constraints:
1 ≤ T ≤ 100, T = number of test cases
1 ≤ n ≤ 50
1 ≤ |contact[i]| ≤ 50
1 ≤ |s| ≤ 6 


*/
//Not solved by trie concept

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        map<string,int>mp;
        
        for(int i=0;i<n;i++)
        mp[contact[i]]++;
        
        vector<vector<string>>ans;
        
        for(int i=0;i<s.size();i++)
        {
            vector<string>v;
            for(auto it:mp)
            {
                if(it.first.substr(0,i+1)==s.substr(0,i+1))
                v.push_back(it.first);
            }
            if(v.size()==0)
            v.push_back("0");
            ans.push_back(v);
        }
        return ans;
    }
};
int main(){
    int t;
    cout<<"Enter the number of test case: ";
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter the number of character: ";
        cin>>n;
        string contact[n], s;
        cout<<"Enter the string of character: ";
        for(int i = 0;i < n;i++)
            cin>>contact[i];

        cout<<"Enter the character: ";
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        cout<<"Answer: "<<endl;
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
