/*

Subtree In N-ary Tree

Given the root of a n-ary tree find the number of duplicate subtrees in the n-ary tree. Two trees are duplicates if they have the same structure with the same node values.

Example 1:

Input:
1 N 2 2 3 N 4 N 4 4 3 N N N N N

Output: 
2
Explanation: 
[4], [3] are duplicate subtree.

*/


#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    vector<Node*> children;
    Node(int val){
        data=val;
    }
};

class N_ary_Tree{
public:
    Node *root;
    int size;
    N_ary_Tree(){
        root=NULL;
        size=0;
    }
    Node *add(int new_key,Node *parent_key=NULL){
        Node *new_node = new Node(new_key);
        if(parent_key == NULL){
            root = new_node;
            size = 1;
        }
        else{
            parent_key->children.push_back(new_node);
            size += 1;
        }
        return new_node;
    }
};


//User function Template for C++

class Solution{
public:
    int duplicateSubtreeNaryTree(Node *root){
        unordered_map<string,int>sub;
        consSubtreeStr(root,sub);
        int count=0;
        for(auto it:sub)
        {
            if(it.second>1)
            {
                count++;
            }
        }
        return count;
    }
    
    private:
    string consSubtreeStr(Node* node,unordered_map<string,int> &sub)
    {
        string s=to_string(node->data)+":";
        vector<string>chilSub;
        for(auto child:node->children)
        {
            chilSub.push_back(consSubtreeStr(child,sub));
        }
        
        sort(chilSub.begin(),chilSub.end());
        for(auto chilSubtree:chilSub)
        {
            s+=chilSubtree + ",";
        }
        sub[s]++;
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        if(i==0){
            string p;
            getline(cin,p);
        }
        string str;
        getline(cin,str);
        stringstream st(str);
        vector<string> s;
        string y;
        while(st>>y){
            s.push_back(y);
        }
        N_ary_Tree *tree = new N_ary_Tree();
        Node *curr;
        queue<Node*> q;
        for(int i=0;i<s.size();i++){
            if (i == 0){
                curr=tree->add(stoi(s[0]));
            }
            else if(s[i] == " "){
                continue;
            }
            else if(q.size() and s[i] == "N"){
                curr = q.front();
                q.pop();
            }
            else if(s[i] != "N"){
                q.push(tree->add(stoi(s[i]), curr));
            }
        }
        Solution ob;
        int res = ob.duplicateSubtreeNaryTree(tree->root);
        cout<<res<<endl;
    }
}