/*
Prefix Suffix String

Given two Lists of strings s1 and s2, you have to count the number of strings in s2 which is either a suffix or prefix of at least one string of s1.

Example 1:

Input:
s1 = ["cat", "catanddog", "lion"]
s2 = ["cat", "dog", "rat"]
Output: 
2
Explanation: 
String "cat" of s2 is prefix of "catanddog"
& string "dog" of s2 is suffix of "catanddog" 

*/

/*
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


//User function Template for C++

class Solution{
public:
struct Node
{
    Node* links[26];
    bool Containskey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void set(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
};

class Trie
{
    Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    void Insert(string& word)
    {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->Containskey(word[i]))
            {
                node->set(word[i],new Node());
            }
            node=node->get(word[i]);
        }
    }
    bool Search(string &word)
    {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->Containskey(word[i]))
            {
                return false;
            }
            node=node->get(word[i]);
        }
        return true;
    }
};

    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        Trie trie;
        for(auto it:s1)
        {
            trie.Insert(it);
            reverse(it.begin(),it.end());
            trie.Insert(it);
        }
        int count=0;
        for(auto it:s2)
        {
            string rev=it;
            reverse(rev.begin(),rev.end());
            if(trie.Search(it) || trie.Search(rev))
            {
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}

*/