/*
#include<iostream>
using namespace std;

class heap     //Declairation of class.
{
public:
    int arr[1000];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)   //insertion operation.
    {
        size = size + 1;    //size of heap at time of inserting element.
        int index = size;   // Declairation of index.

        arr[index] = val;
        int parent = index / 2;   // Parent node declairation.
        while (index > 1)
        {

            int parent = index / 2;
            if (arr[parent] < arr[index])    //check that the parent node is greter than child node?
             {
                swap(arr[parent], arr[index]);  //if parent less than child the swap.
                index = parent;
            }
            else
            {
                return;     //return ans.
            }
        }
    }

    void deletion()
    {
        if(size==0)    //if the size is 0 the simply return
        {
            cout<<"\nNo Element in Heap.";
            return;
        }
        arr[1] = arr[size];     //store last element in first index
        size--;               //reduce size after complition of delete operation
        int i = 1;

        int leftindex = 2 * i;   //leftside of index.
        int rightindex = 2 * i + 1;    //right of index

        while (size > i)
        {
            if (arr[leftindex] > arr[i] && leftindex < size)    //check that parent node is greater than child
            {
                swap(arr[leftindex], arr[i]);  //if not the  simply swap.
                i = leftindex;   //storing leftindex in i
            }
            else if (arr[rightindex] > arr[i] && rightindex < size)    //check that parent node is greater than child
            {
                swap(arr[rightindex], arr[i]);  //if not the  simply swap.
                i = rightindex;    //storing rightindex in i
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        cout << "\nThe values: ";
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    heap h1;

    int n;
    cout << "Entre the limit of number: ";
    cin >> n;
    int val;
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        h1.insert(val);
    }
    h1.print();

    cout<<"\nAfter deleting element: ";
    h1.deletion();
    h1.print();
    return 0;
}

*/

#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size=0;

    heap()
    {
        arr[0]=-1;
        size=0;
    }

    void insert(int x)
    {
        size=size+1;
        int index=size;
        arr[index]=x;

        while(index>1)
        {
            int parent=index/2;

            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        cout<<"The velues of heaps are: ";
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }

    void deletefrom()
    {
        if(size==0)
        {
            cout<<"No element.";
            return;
        }

        arr[1]=arr[size];

        size--;

        int i=1;
        while(i<size)
        {
            int leftIndex=2*i;
            int rightIndex=2*i+1;

            if(leftIndex<size and arr[leftIndex]>arr[i])
            {
                swap(arr[leftIndex],arr[i]);
                i=leftIndex;
            }
            else if(rightIndex<size and arr[rightIndex]>arr[i])
            {
                swap(arr[rightIndex],arr[i]);
                i=rightIndex;
            }
            else
            {
                return;
            }
        }   
    }
};

int main(){
    int arr[]={50,55,53,52,54,56};
    int n=sizeof(arr)/sizeof(arr[0]);
    heap h;
    for(int i=0;i<n;i++)
    {
        h.insert(arr[i]);
    }
    h.print();
    h.deletefrom();
    cout<<endl;
    h.print();
return 0;
}















































