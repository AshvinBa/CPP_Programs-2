#include <iostream>
using namespace std;

class heap
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
    return 0;
}




