#include<stdio.h>

void heapify(int arr[],int n, int i)
{
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	int temp;

	if(left < n && arr[left] > arr[largest])
		largest =left;

	if(right < n && arr[right] > arr[largest])
		largest =right;

	if(largest!=i)
	{
		// swap arr[i], arr[largest]
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		heapify(arr,n,largest);	
	}
}

void heapsort(int arr[], int n)
{
	int i, temp;
	for(i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
	
	for(i=n-1;i>0;i--)
	{
		//swap arr[0],arr[i]
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;

		heapify(arr,i,0);
	}
}

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {12,-11,0,13,15,6,7};
	int n = sizeof(arr) / sizeof(arr[0]);

	heapsort(arr,n);
	printf("\nSorted array = \n");
	printArray(arr,n);
}

