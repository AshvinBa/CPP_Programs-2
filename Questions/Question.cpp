#include <bits/stdc++.h>
using namespace std;
bool sum(int arr[], int n)
{
    unordered_set<int> s;
    int pre_sum = 0;

    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];

        if (pre_sum == 0)
            return true;

        if (s.find(pre_sum) != s.end())
            return true;

        s.insert(pre_sum);
    }
    return false;
}

int main()
{
    int n;
    int arr[] = {4, 2, 1, 6};
    n = sizeof(arr) / sizeof(arr[0]);
    bool x = sum(arr, n);
    if (x == true)
    {
        cout << "Yes.";
    }
    else
    {
        cout << "No.";
    }
    return 0;
}

/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool sum(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            return true;
        }
    }
    int ans;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        ans=arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==abs(ans))
            {
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n;
    int arr[]={4,2,1,6};
    n=sizeof(arr)/sizeof(arr[0]);
    bool x=sum(arr,n);
    if(x==true)
    {
        cout<<"Yes.";
    }
    else
    {
        cout<<"No.";
    }
return 0;
}
*/

/*

#include<iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front,rear;
    int size;

    public:

    CircularQueue(int n)
    {
        size=n;
        arr=new int[size];
        front=rear=-1;
    }
    void enqueue();
    int dequeue();
    void display();
};

void CircularQueue::enqueue()
{
    if((front==0 && rear==size-1)||(rear==(front-1)%(size-1)))
    {
        cout<<"The Queue is Full.";
    }
    else if(front==-1)
    {
        rear=front=0;
    }
    else if(rear==size-1 && front!=0)
    {
        rear=0;
    }
    else
    {
        rear++;
    }
    int val;
    cout<<"Enter the value: ";
    cin>>val;
    arr[rear]=val;
};

int CircularQueue::dequeue()
{
    if(front==-1)
    {
        cout<<"The Queue is Empty.";
    }
    int ans=arr[front];
    return ans;

    if(front==rear)
    {
        rear=front=-1;
    }
    else if(front==size-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
};

void CircularQueue::display()
{
    if(front==-1)
    {
        cout<<"The Queue is Empty.";
    }
    else if(front>rear)
    {
        for(int i=rear;i<=front;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    else if(front<rear)
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    CircularQueue CQ(n);

    CQ.enqueue();
return 0;
}

*/

/*

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> push(int arr[],int n)
{
    vector<int>v1;
    vector<int>v2;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            v1.push_back(arr[i]);
        }
        else
        {
            v2.push_back(arr[i]);
        }
    }
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
    }
}
int main(){
    int arr[]={4,5,-1,6,8,7,-2,-3};
    int n=sizeof(arr)/sizeof(arr[0]);
    push(arr,n);
return 0;
}

*/

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// vector<int> common_ele(vector<int>v1,vector<int>v2,vector<int>v3,int n1,int n2,int n3)
// {
//     vector<int>ans;
//     unordered_map<int,int>m1,m2,m3;

//     for(int i=0;i<n1;i++)
//     {
//         m1[v1[i]]++;
//     }
//     for(int i=0;i<n2;i++)
//     {
//         m2[v2[i]]++;
//     }
//     for(int i=0;i<n3;i++)
//     {
//         m3[v3[i]]++;
//     }

//     for(int i=0;i<n1;i++)
//     {
//         if(m1[v1[i]]==m2[v1[i]] && m2[v1[i]]==m3[v1[i]])
//         {
//             ans.push_back(v1[i]);
//         }
//     }
//     return ans;
// }

// int main(){
//     int n1,n2,n3;
//     cout<<"Enter the size for v1,v2,v3: ";
//     cin>>n1>>n2>>n3;

//     vector<int>v1(n1);
//     vector<int>v2(n2);
//     vector<int>v3(n3);
//     cout<<"Enter the values of v1: ";
//     for(int i=0;i<n1;i++)
//     {
//         cin>>v1[i];
//     }
//     cout<<"Enter the values of v2: ";
//     for(int i=0;i<n2;i++)
//     {
//         cin>>v2[i];
//     }
//     cout<<"Enter the values of v1: ";
//     for(int i=0;i<n3;i++)
//     {
//         cin>>v3[i];
//     }
//     vector<int>res=common_ele(v1,v2,v3,n1,n2,n3);
//     for(auto i=res.begin();i<res.end();i++)
//     {
//         cout<<*i<<" ";
//     }
// return 0;
// }