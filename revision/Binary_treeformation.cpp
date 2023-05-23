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

node* builtTree(node* root)
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
    root->left=builtTree(root->left);

    cout<<"Enter the value for at right of: "<<data;
    root->right=builtTree(root->right);
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
            root=builtTree(root);
        }
        break;

        case 2:
        {
            cout<<"\nInOrder Traversal of the Tree is: ";
            print(root);
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








