#include<bits/stdc++.h>
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

void buildfromLevelOrder(node* &root)
{
    queue<node*>q;
    int data;
    cout<<"Enter the first node: ";
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        cout<<"Enter the left node for: "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1)
        {
            temp->left=new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the right node for: "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1)
        {
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}

void level_ordere_Traversal(node* root)
{
    cout<<"\n";
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }    
}


int main(){
    node* root=NULL;
    buildfromLevelOrder(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    level_ordere_Traversal(root);
return 0;
}


/*
OUTPUT


Enter the first node: 1
Enter the left node for: 1
3
Enter the right node for: 1
5
Enter the left node for: 3
7
Enter the right node for: 3
11
Enter the left node for: 5
17
Enter the right node for: 5
-1
Enter the left node for: 7
-1
Enter the right node for: 7
-1
Enter the left node for: 11
-1
Enter the right node for: 11
-1
Enter the left node for: 17
-1
Enter the right node for: 17
-1

1
3 5
7 11 17
*/