#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void check_for_BST(node* root,node* prev,int &f)
{
    if(root==NULL)
    return;

    check_for_BST(root->left,prev,f);
    if(prev!=NULL && prev->data>=root->data)
    {
        f=0;
        return;
    }
    prev=root;
    check_for_BST(root->right,prev,f);
}
bool checkBST(node* root)
{
    int f=1;
    node* prev=NULL;
    check_for_BST(root,prev,f);
    return f;
}
node* builtTree(node* &root)
{
    int data;
    cout<<"\nEnter the data: ";
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }

    root=new node(data);

    cout<<"Enter the value for at left of: "<<data; 
    root->right=builtTree(root->left);

    cout<<"Enter the value for at right of: "<<data;
    root->right=builtTree(root->right);

    return root;
}

node* print(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);

}

int main(){
    
    node* root=NULL;
    builtTree(root);
    int k=checkBST(root);
    if(k==1)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
return 0;
}