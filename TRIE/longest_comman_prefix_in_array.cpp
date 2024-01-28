/*
Longest Common Prefix in an Array
Given an array of N strings, find the longest common prefix among all strings present in the array.

Example 1:
Input:
N = 4
arr[] = {geeksforgeeks, geeks, geek,
         geezer}
Output: gee
Explanation: "gee" is the longest common
prefix in all the given strings.

Example 2:
Input: 
N = 2
arr[] = {hello, world}
Output: -1
Explanation: There's no common prefix
in the given strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonPrefix() which takes the string array arr[] and its size N as inputs and returns the longest common prefix common in all the strings in the array. If there's no prefix common in all the strings, return "-1".

Expected Time Complexity: O(N*min(|arri|)).
Expected Auxiliary Space: O(min(|arri|)) for result.
*/


// Approach - 1

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        sort(arr,arr+N);
        string a=arr[0];
        string b=arr[N-1];
        string ans="";
        for(int i=0;i<a.length();i++)
        {
            if(a[i]==b[i])
            {
                ans+=a[i];
            }
            else
            {
                break;
            }
        }
        if(ans.size()>0)
        {
            return ans;
        }
        else
        {
            return "-1";
        }
    }
};
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}




/*

// Approach -2

#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public: 
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;
    
    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        childCount=0;
        isTerminal=false;
    }
};

class Trie
{
    public:
    TrieNode* root;
    
    Trie(char ch)
    {
        root=new TrieNode(ch);
    }
    
    void insertUtil(TrieNode* root,string word)
    {
        // base case
        if(word.length()==0)
        {
            root->isTerminal=true;
            return;
        }

        // assumption , word will be capital
        int index=word[0]-'A';
        TrieNode* child;

        // present
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            // absent
            child=new TrieNode(word[0]);
            root->childCount++;
            root->children[index]=child;
        }
        // recursion
        insertUtil(root,word.substr(1));
    }
    
    void insertWord(string word)
    {
        insertUtil(root,word);
    }
    
    void lcp(string str,string &ans)
    {
        for(int i=0;i<str.length();i++)
        {
            char ch=str[i];
            
            if(root->childCount==1)
            {
                ans.push_back(ch);
                // move next
                int index=ch-'a';
                root=root->children[index];
            }
            else
            {
                break;
            }
            
            if(root->isTerminal)
            break;
        }
    }
    
};

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        Trie *t=new Trie('\0');
        // insert all string into trie.
        for(int i=0;i<N;i++)
        {
            t->insertWord(arr[i]);
        }
        string first=arr[0];
        string ans="";
        
        t->lcp(first,ans);
        return ans;
    }
};
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}
*/