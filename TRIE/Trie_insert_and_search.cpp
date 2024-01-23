/*
Trie | (Insert and Search)

Trie is an efficient information retrieval data structure. Use this data structure to store strings and search other strings. Your task is to use Trie data structure to insert and search the given strings. Firstly, N strings will be added to the Trie and then a string will be used to test the search function. Return 1 if a given string is stored in Trie, else return 0.

Note: Strings will have all their characters as lower-case english alphabets. Read Your Task Section carefully.

Example 1:
Input:
N = 8
key[] = {the, a, there, answer,
         any, by, bye, their}
S = the
Output: 1
Explanation: 
"the" is present in the given set of
strings "the", "a", "there", "answer", "any",
"by", "bye", "their"

Example 2:
Input:
N = 8
key[] = {the, a, there, answer,
         any, by, bye, their}
S = geeks
Output: 0
Explanation: 
"geeks" is not present in the
given set of strings.
Your Task:
You do not have to take any input or print anything. Complete insert and search functions. 

insert function takes a root node of the Trie and a string as an input, changes the root value in-place and returns nothing.
search function takes a root node of the Trie and a string as an input, returns true if string is found in the Trie, else false.

In case of true, driver code prints 1 and in the case of false, 0 is printed.
Expected Time Complexity: O(M+|S|).
Expected Auxiliary Space: O(M).
M = sum of the length of all strings which are present in the key[] 
|S| denotes the length of the string search.

Constraints:
1 <= N <= 104
1 <= |input strings| <= 30

*/


#include <bits/stdc++.h>

using namespace std;

#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}

class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string word)
        {
            struct TrieNode *pCrawl = root;
            for (int i = 0; i < word.length(); i++) 
            {
            int index = CHAR_TO_INDEX(word[i]);
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
            }
            pCrawl->isLeaf = true;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string word) 
        {
            struct TrieNode *pCrawl = root;
            for (int i = 0; i < word.length(); i++)
            {
            int index = CHAR_TO_INDEX(word[i]);
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
            }
        return (pCrawl != NULL && pCrawl->isLeaf);
        }
};

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cout<<"Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        cout<<"Enter the size: ";
        int n;
        cin >> n;
        string keys[n];
        cout<<"Enter the Keys: ";
        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }
        
        Solution obj;
        struct TrieNode *root = getNode();
        for (int i = 0; i < n; i++) obj.insert(root, keys[i]);
        string abc;
        cout<<"Enter the key for search: ";
        cin >> abc;
        if (obj.search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}