#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildTree(Node* &root)
{
    int val;
    cout<<"\nEnter the values: ";
    cin>>val;
    
    if(val==-1)
    {
        return NULL;
    }
    root=new Node(val);

    cout<<"Insert at Left of: "<<val<<endl;
    root->left=buildTree(root->left);

    cout<<"Insert at Right of: "<<val<<endl;
    root->right=buildTree(root->right);

    return root;
}

void InOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";

}

int main()
{
    Node* root=NULL;
    cout<<"Built Tree.\n";
    buildTree(root);
    cout<<"\nInOrder Traversal: ";
    InOrderTraversal(root);
    cout<<"\nPreOrder Traversal: ";
    PreOrderTraversal(root);
    cout<<"\nPostOrder Traversal: ";
    PostOrderTraversal(root);
}


