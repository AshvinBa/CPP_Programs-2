#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the row and coloumn: ";
    cin >> n >> m;

    int **arr = new int *[n];
    cout << "Enter the values of array: ";
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Print matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}