#include<iostream>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie
{
    public: 
    TrieNode* root;

    Trie()
    {
        root=new TrieNode('\0');
        return ;
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
            root->children[index]=child;
        }

        // recursion
        insertUtil(root,word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root,word);
    }


    bool searchUtil(TrieNode* root, string word)
    {
        // base case
        if(word.length()==0)
        {
            return root->isTerminal;
        }

        int index=word[0] - 'A';
        TrieNode* child;

        // present.
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        { // absent.
            return false;
        }

        // Recursion.
        return searchUtil(root,word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root,word);
    }

};


int main(){
    Trie *t=new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    t->insertWord("dtfhrfhurfyxhnd36784s5163g163g163g786sey9rdg6541fd65vhg41364154657488");
    t->insertWord("dtfhrfhurfyxhnd36784s5163g163");

    cout<<"Present or not: "<<t->search("dtfhrfhurtfjhgnfdcrtnghfyxhnd36784s5163g163g163g786sey9rdg6541fd65vhg41364154657488");
return 0;
}











