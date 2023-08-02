/*
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int large=i;
    int left=2*i;
    int right=2*i-1;

    if(left<=n && arr[large]<arr[left])
    {
        large=left;
    }
    if(right<=n && arr[large]<arr[right])
    {
        large=right;
    }
    
    if(large!=i)
    {
        swap(arr[large],arr[i]);
        heapify(arr,n,large);
    }
}

void heap_sort(int arr[],int n)
{
    int size=n;
    while(size>1)
    {
        swap(arr[1],arr[size]);
        size--;
    
        heapify(arr,size,1);
    }
}

void build_Heap(int arr[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
}

void print(int arr[],int n)
{
    cout<<"\nSorted Array: ";
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    cout<<"Enter the Limit: ";
    cin>>n;

    int arr[n];
    cout<<"\nEnter the values: "; 
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build_Heap(arr,n);
    heap_sort(arr,n);
    print(arr,n);
}
*/

/*
#include<iostream>
using namespace std;

int stack[1000],top=-1,size=10;

void push(int x)
{
    if(top==size)
    {
        cout<<"\nStack is full.";
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top==-1)
    {
        cout<<"\nNo Element in stack.";
    }
    else
    {
        int val=stack[top--];
        cout<<"\nDeleted Element is: "<<val;
    }
}

void display()
{
    cout<<"\nThe Elements are: ";
    for(int i=0;i<=top;i++)
    {
        cout<<stack[i]<<" ";
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    display();
    pop();
    pop();
    pop();
    pop();
    display();
    return 0;
}
*/

/*
#include<iostream>
using namespace std;

int queue[200],front=-1,rear=-1,size=10;

void push(int x)
{
    if(rear==size)
    {
        cout<<"\nThe Queue is Full.";
    }
    else if(rear==-1)
    {
        rear=front=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }    
}

void pop()
{
    if(front==rear || front==size)
    {
        cout<<"\nThe Queue is Empty.";
    }
    else
    {
        int val=queue[front];
        front++;
        cout<<"\nThe Deleted Element is: "<<val;
    }
}

void display()
{
    cout<<"\nThe Elements in stack is: ";
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i]<<" ";
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    display();
    pop();
    pop();
    pop();
    display();
    
return 0;
}
*/

/*
#include<iostream>
using namespace std;

int queue[200],front=-1,rear=-1,n=10;

void push(int x)
{
    if((rear+1)%n==n)
    {
        cout<<"\nThe queue is Full.";
        return;
    }
    else if(rear==-1 && front==-1)
    {
        rear=front=0;
        queue[rear]=x;
    }
    else
    {
        rear=(rear+1)%n;
        queue[rear]=x;
    }

}

void pop()
{
    if((front+1)%n==rear || front==-1)
    {
        cout<<"\nThe Queue is Empty.";
        return;
    }
    else
    {
        int val=queue[front];
        front=(front+1)%n;
        cout<<"\nThe Deleted Element is: "<<val;
    }
}

void display()
{
    if(rear==-1)
    {
        cout<<"The Queue is Empty.";
        return;
    }
    cout<<"\nThe Queue is: ";
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i]<<" ";
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    display();
    pop();
    pop();
    pop();
    display();
return 0;
}
*/
/*
//Tree InOrder Traversal

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

Node* builde_Tree(Node* &root)
{
    int val;
    cout<<"\nEnter the data: ";
    cin>>val;
    if(val==-1)
    {
        return NULL;
    }
    root=new Node(val);
    
    cout<<"Insert Data at Left of: "<<val;
    root->left=builde_Tree(root->left);

    cout<<"Insert Data at Right of: "<<val;
    root->right=builde_Tree(root->right);

    return root;
}

void inOrderTrav(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    inOrderTrav(root->left);
    cout<<" -> "<<root->data;
    inOrderTrav(root->right);
}

int main(){
    Node* root=NULL;
    builde_Tree(root);
    cout<<"The Elements are:";
    inOrderTrav(root);    
return 0;
}
*/

/*
// LINKED LIST
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }

    ~Node()
    {
        int val=this->data;
        if(this->next!=NULL)
        {
            this->next=NULL;
            delete next;
        }
        cout<<"\nYour deleted element is: "<<val;
    }
};

void insertAthead(Node* &head,Node* &tail,int val)
{
    Node* node=new Node(val); 
    if(head==NULL)
    {
        head=node;
        tail=node;
        return;        
    }
    head->prev=node;
    node->next=head;
    head=node;
}

void insertAttail(Node* &head,Node* &tail,int val)
{
    Node* node=new Node(val);
    if(head==NULL)
    {
        head=node;
        tail=node;
        return;
    }
    tail->next=node;
    node->prev=tail;
    node->next=NULL;
    tail=node;
}

void insertAtposition(Node* &head,Node* &tail,int val,int pos)
{
    if(pos==1)
    {
        insertAthead(head,tail,val);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;
    }

    if(temp->next==NULL)
    {
        insertAttail(head,tail,val);
        return;
    }
    Node* node=new Node(val);
    node->next=temp->next;
    temp->next->prev=node;
    temp->next=node;
    node->prev=temp;
}

void deleteatHead(Node* &head,Node* &tail)
{
    if(head==NULL)
    {
        cout<<"No Element in List.";
        return;
    }
    else
    {
        Node* temp=head;
        head=head->next;
        delete temp;
    }
}

void deleteatTail(Node* &head,Node* &tail)
{
    Node* temp=tail;
    if(tail==NULL)
    {
        cout<<"No Element in List.";
        return;
    }
    temp->prev->next=NULL;
    tail=temp->prev;
    delete temp;
}

void deleteatposition(Node* &head,Node* &tail,int pos)
{
    if(pos==1)
    {
        deleteatHead(head,tail);
        return;
    }

    int cnt=1;
    Node* temp=head;
    Node* prev=NULL;

    while(cnt<pos)
    {
        prev=temp;
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        deleteatTail(head,tail);
        return;
    }
    prev->next=temp->next;
    temp->next->prev=prev;
    delete temp;    
}


void display(Node* &head)
{
    if(head==NULL)
    {
        cout<<"No Element in list.";
        return;
    }
    else
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    int s;
    do
    {
    cout<<"\n"<<endl;
    cout<<"\t***OPERATION IN LINKED LIST***"<<endl;
    cout<<"\t1)INSERT AT HEAD."<<endl;
    cout<<"\t2)INSERT AT TAIL."<<endl;
    cout<<"\t3)INSERT AT SPECIFIC POSITION."<<endl;
    cout<<"\t4)DELETE AT HEAD."<<endl;
    cout<<"\t5)DELETE AT TAIL."<<endl;
    cout<<"\t6)DELETE AT SPECIFIC POSITION."<<endl;
    cout<<"\t7)DISPLAY ELEMENTS."<<endl;
    cout<<"\t8)TO EXIT."<<endl;
    cout<<"\tEnter your choise: ";
    cin>>s;
    
    switch(s)
    {
        case 1:
        {
            int n;
            cout<<"Enter to Insert: ";
            cin>>n;
            insertAthead(head,tail,n);
        }
        break;

        case 2:
        {
            int n;
            cout<<"Enter to Insert: ";
            cin>>n;
            insertAttail(head,tail,n);
            
        }
        break;

        case 3:
        {
            int n,pos;
            cout<<"Enter to Insert: ";
            cin>>n;
            cout<<"Enter the position: ";
            cin>>pos;
            insertAtposition(head,tail,n,pos);
        }
        break;

        case 4:
        {
            deleteatHead(head,tail);            
        }
        break;

        case 5:
        {
            deleteatTail(head,tail);
        }
        break;

        case 6:
        {
            int pos;
            cout<<"Enter the position: ";
            cin>>pos;
            deleteatposition(head,tail,pos);
        }
        break;

        case 7:
        {
            display(head);
        }
        break;

        case 8:
        {
            cout<<"\n\tExit\n";
        }
        break;
    }
    }
    while(s!=8);
    return 0;
}
*/
/*
// heap sort
#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int large=i;
    int left=2*i;
    int right=2*i-1;

    if(left<=n && arr[large]<arr[left])
    {
        large=left;
    }
    if(right<=n && arr[large]<arr[right])
    {
        large=right;
    }

    if(large!=i)
    {
        swap(arr[large],arr[i]);
        heapify(arr,n,large);
    }
}

void build_heap(int arr[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
}

void heap_sort(int arr[],int n)
{
    int size=n;
    while(size>1)
    {
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}

void display(int arr[],int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
}


int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the values: ";
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build_heap(arr,n);   
    cout<<"\nThe sorted array is: ";
    heap_sort(arr,n); 
    display(arr,n);
return 0;
}
*/

/*
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
        data=val;
        left=NULL;
        right=NULL;
    } 
};

Node* build_Tree(Node* &root)
{
    int val;
    cout<<"Enter the value: ";
    cin>>val;

    if(val==-1)
    {
        return NULL;
    }
    root=new Node(val);

    cout<<"Insert at Left of: "<<val<<endl;
    root->left=build_Tree(root->left);

    cout<<"Insert at Right of: "<<val<<endl;
    root->right=build_Tree(root->right);

    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<" -> "<<root->data;
    inorder(root->right);
}


int main(){
    Node* root=NULL;
    build_Tree(root);
    cout<<"\nInOrder Traversal: ";
    inorder(root);    
return 0;
}
*/

// Prefix to Suffix

/*

#include<iostream>
using namespace std;

char stack[200];
int top=-1;

void push(char x)
{
    stack[++top]=x;
}

char pop()
{
    if(top==-1)
    return -1;
    else
    return stack[top--];
}

int priority(char x)
{
    if(x=='(')
    {
        return 0;
    }
    if(x=='+' || x=='-')
    {
        return 1;
    }
    if(x=='*' || x=='/')
    {
        return 2;
    }
}


int main(){
    char exe[200];
    char *e,x;
    cout<<"Enter the Expression: ";
    cin>>exe;
    
    e=exe;

    while(*e!='\0')
    {
        if(isalnum(*e))
        {
            cout<<*e;
        }
        else if(*e=='(')
        {
            push(*e);
        }
        else if(*e==')')
        {
            while((x=pop())!='(')
            cout<<x;
        }
        else
        {
            while(priority(stack[top])>=priority(*e))
            cout<<pop();

            push(*e);
        }
        e++;
    }
    while(top!=-1)
    {
        cout<<pop();
    }

return 0;
}
*/
/*
// Tree with NonRecursive sol
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* buildTree(Node* &root)
{
    int val;
    cout<<"Enter the data: ";
    cin>>val;

    if(val==-1)
    {
        return NULL;
    }
    root=new Node(val);

    cout<<"at left: "<<val<<endl;
    root->left=buildTree(root->left);

    cout<<"at right: "<<val<<endl;
    root->right=buildTree(root->right);

    return root;
}

void inorder(Node* root)
{
    stack<Node*>s;
    Node* T=root;

    while(T!=NULL)
    {
        s.push(T);
        T=T->left;
    }
    while(!s.empty())
    {
        T=s.top();
        s.pop();
        cout<<"->"<<T->data;
        T=T->right;
        while(T!=NULL)
        {
            s.push(T);
            T=T->left;
        }
    }
}

int main(){
    Node* root=NULL;
    buildTree(root);
    cout<<"The Traversal Element is: ";
    inorder(root);
return 0;
}
*/

/*
#include<iostream>
using namespace std;

char stack[200];
int top=-1;

void push(char x)
{
    stack[++top]=x;
}

char pop()
{
    if(top==-1)
    return -1;
    else
    return stack[top--];
}

int priority(char x)
{
    if(x=='(')
    {
        return 0;
    }
    if(x=='+' || x=='-')
    {
        return 1;
    }
    if(x=='*' || x=='/')
    {
        return 2;
    }
}

int main(){
    char exp[200];
    char *e,x;
    
    cout<<"Enter the expression: ";
    cin>>exp;

    e=exp;

    while(*e!='\0')
    {
        if(isalnum(*e))
        {
            cout<<*e;
        }
        else if(*e=='(')
        {
            push(*e);
        }
        else if(*e==')')
        {
            while((x=pop())!='(')
            cout<<x;            
        }
        else
        {
            while(priority(stack[top])>=priority(*e))
            cout<<pop();

            push(*e);
        }
        e++;

    }
    while(top!=-1)
    {
        cout<<pop();
    }
    
return 0;
}
*/
/*

#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int large=i;
    int left=2*i;
    int right=2*i-1;

    if(left<=n && arr[large]<arr[left])
    {
        large=left;
    }
    if(right<=n && arr[large]<arr[right])
    {
        large=right;
    }
    
    if(large!=i)
    {
        swap(arr[large],arr[i]);
        heapify(arr,n,large);
    }
}

void build_heap(int arr[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
}

void sort(int arr[],int n)
{
    int size=n;
    while(size>1)
    {
        swap(arr[1],arr[size]);
        size--;

        heapify(arr,size,1);
    }
}

void display(int arr[],int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    int arr[n];
    
    cout<<"Enter the values: ";
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    build_heap(arr,n);
    cout<<"Sorted array: ";
    sort(arr,n);
    display(arr,n);
return 0;
}
*/
