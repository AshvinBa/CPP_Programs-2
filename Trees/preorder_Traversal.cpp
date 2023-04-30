#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* builtTree(node* root)
{
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    root=new node(data);

    cout<<"Enter the data for inserting at left: "<<data<<endl;
    root->left=builtTree(root->left);

    cout<<"Enter the data for inserting at right: "<<data<<endl;
    root->right=builtTree(root->right);

    return root;
}

void preorder(node* root)
{
    if(root==NULL)
    return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node* root=NULL;

    root=builtTree(root);

    cout<<"\nInorder Traversal: ";    
    preorder(root);
    return 0;
return 0;
}

//OUTPUT
// Enter the data: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// Inorder Traversal: 1 3 7 11 5 17