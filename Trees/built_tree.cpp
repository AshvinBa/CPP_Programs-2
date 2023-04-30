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


int main(){
    node* root=NULL;

    root=builtTree(root);

    return 0;
return 0;
}









