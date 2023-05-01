#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* BuildTree(Node* root)
{
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    root=new Node(data);

    cout<<"Enter data for inserting at Left of: "<<data<<endl;
    root->left=BuildTree(root->left);

    cout<<"Enter data for inserting at Right of: "<<data<<endl;
    root->right=BuildTree(root->right);
    
    return root;
}

void InOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

int main(){

    Node* root=NULL;
    int s;
    do{
    cout<<"\n\n***Operations In Tree.***"<<endl;
    cout<<"   Press-1. To Build Tree."<<endl;
    cout<<"   Press-2. To InOrder Travers."<<endl;
    cout<<"   Press-3. Exit."<<endl;
    cout<<"   Enter your choice: ";
    cin>>s;

    switch(s)
    {
        case 1:
        {
            root=BuildTree(root);
        }
        break;

        case 2:
        {
            cout<<"\nInOrder Traversal of the Tree is: ";
            InOrder(root);
        }
        break;
        
        case 3:
        {
            cout<<"Exit.";
        }
        break;
    }
    }
    while(s!=3);
return 0;
}






