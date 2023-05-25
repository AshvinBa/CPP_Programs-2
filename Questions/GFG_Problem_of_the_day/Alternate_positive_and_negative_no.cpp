#include <iostream>
using namespace std;

void rearrange(long long *arr, int n) 
    {
    int max_index=n-1;
	int min_index=0;
	int max=arr[n-1]+1;
	
	for(int i=0;i<n;i++)
	{
	    if(i%2==0)
	    {
	        arr[i]=(arr[max_index]%max)*max+arr[i];
	        max_index--;
	    }
	    else
	    {
	        arr[i]=(arr[min_index]%max)*max+arr[i];
	        min_index++;
	    }
	}
	for(int i=0;i<n;i++)
	{
	    arr[i]/=max;
	}	 
}

int main()
{
    long long arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    cout << "\nAnswer: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}