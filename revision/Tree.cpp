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

    cout<<"Enter the data at left of: "<<data<<endl;
    root->left=builtTree(root->left);

    cout<<"Enter the data at right of: "<<data<<endl;
    root->right=builtTree(root->right);

    return root;
}

void inorder(node* root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    cout<<"Hello ";
    node* root=NULL;
    root=builtTree(root);
    inorder(root);
return 0;
}