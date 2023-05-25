/*
Construct a Full Binary Tree
MediumAccuracy: 78.99%Submissions: 10K+Points: 4
Finding A Job Is Now Easier Than Today's Problem! Explore Job Fair 2023

Given two arrays that represent Preorder traversals of a Full binary tree preOrder[] and its mirror tree preOrderMirror[], your task is to complete the function constructBinaryTree(), that constructs the full binary tree using these two Preorder traversals.

Note: It is not possible to construct a general binary tree using these two traversal. But it is possible to create a full binary tree using the above traversals without any ambiguity.

Example 1:

Input :
preOrder[] = {0,1,2}
preOrderMirror[] = {0,2,1} 

Output :
                0
              /   \
             1     2
Explanation :
Tree in the output and it's mirror tree matches the preOrder and preOrderMirror.
Example 2:

Input :  
preOrder[] = {1,2,4,5,3,6,7}
preOrderMirror[] = {1,3,7,6,2,5,4}

Output :          
                 1
               /    \
              2      3
            /   \   /  \
           4     5 6    7
Explanation :
Tree in the output and it's mirror tree matches the preOrder and preOrderMirror.

*/



#include<iostream>
using namespace std;
class node{
    public:
    node* left=NULL;
    node* right=NULL;
    int data;
    
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }  
};

node* help(int &index,int start,int end,int pre[],int preMirror[],int n)
{
    if(index>=n or start>end)
    return NULL;

    if(index==n || start==end)
    {
        node* temp=new node(pre[index]);
        index++;
        return temp;
    }
    node* temp=new node(pre[index]);
    index++;

    for(int i=start;i<=end;i++)
    {
        if(pre[index]==preMirror[i])
        {
            temp->left=help(index,i,end,pre,preMirror,n);
            temp->right=help(index,start+1,i-1,pre,preMirror,n);
            break;
        }
    }
    return temp;
}

node* constructBinaryTree(int pre[], int preMirror[], int size)
{
    int index=0;
    return help(index,0,size-1,pre,preMirror,size);
}

void printInorder(node* node1)
{
	if (node1 == NULL)
    return;
	printInorder(node1->left);
	cout<<node1->data<<" ";
	printInorder(node1->right);
}

int main()
{
        int n;
        cout<<"Enter the size: ";
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
        cout<<"Enter the values for Pre: ";
	    for(int i=0; i<n; i++)
        {
        cin>>preOrder[i];
        }
        cout<<"Enter the values for PreMirror: ";
	    for(int i=0; i<n; i++)
        {
        cin>>preOrderMirror[i];
        }
        printInorder(constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
	return 0;
}