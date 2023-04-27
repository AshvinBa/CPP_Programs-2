/*
Easy Task

Given a string s whose length is n and array queries of length q where each elements of queries is either of type 1 query or type 2 query which is explained ahead.

There are two types of query.

Query type 1 : ["1",ind,char]  "1" denotes this is type 1 query. In this query you have to change the character at index ind in s to character char.(Data type of ind,char is string in input)

Query Type 2: ["2",left,right,k]  "2" denotes this is type 2 query. In this query you have to return kth lexographically largest character  in the subtring of s (it is the kth largest character in sorted order , not the kth distinct character) starting from index left and ending at index right both left and right are inclusive. (Data type of left,right,k is string in input)

You have to perform each query in the same order as given in  queries and return an array res such that res array contains the answer for each type2 query in same order as it appeared in queries.

Note : 0 based indexing is used.

Example 1:

Input:
n=4
s="abab"
q=2
queries={{"1","2","d"},{"2","1","3","1"}}
Output:
{"d"}
Explanation:
First query is of type 1 so after changing character at index 2
to d  s becomes abdb . Now Second query is of type 2 in which
the 1st(k=1) lexographically largest character is "d" in substring "bdb"(s[1:3]). So we
returned a array with result of type 2 query {"d"}.
*/

#include <bits/stdc++.h>
using namespace std;

char solve(int frequency[], int n)
{
    int cnt = 0;
    for (int i = 25; i >= 0; i--)
    {
        cnt += frequency[i];
        if (cnt >= n)
        {
            return i + 'a'; // b-a=1
        }                   // a-a=0
    }
    return '#';
}

vector<char> easyTask(int n, string s, int q, vector<vector<string>> &queries)
{
    // Code here
    vector<char> ans;

    for (int i = 0; i < queries.size(); i++)
    {
        int queno = stoi(queries[i][0]);
        if (queno == 1)
        {
            int ind = stoi(queries[i][1]);
            char ch = queries[i][2][0];
            s[ind] = ch;
        }
        else
        {
            int left = stoi(queries[i][1]);
            int right = stoi(queries[i][2]);
            int k = stoi(queries[i][3]);
            int freq[26] = {0};
            for (int i = left; i <= right; i++)
            {
                // a-a=0
                // b-a=1
                int ele = s[i] - 'a';
                freq[ele]++;
            }
            char ch = solve(freq, k);
            ans.push_back(ch);
        }
    }
    return ans;
}

int main()
{
    int t;
    cout<<"How many time you want: ";
    cin>>t;
    while(t--){
        int n;
        // cin>>n;
        string s;
        cout<<"Enter the string: ";
        cin>>s;
        n=s.length();
        int q;
        cout<<"Enter the number of query: ";
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        
        vector<char> ans=easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
