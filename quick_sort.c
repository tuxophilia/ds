#include<stdio.h>
int partition(int arr[],int low, int up);

int quick_sort(int arr[],int low, int up)
{
	int pivotloc;
	if(low>=up)
	return;
	pivotloc=partition(arr,low,up);

	quick_sort( arr, low,  pivotloc-1);
	quick_sort( arr, pivotloc+1, up );
		
}

int partition(int arr[],int low, int up)
{
	int i,j,pivot,temp;
	i=low+1;
	j=up;
	pivot=arr[low];
	while(i<=j)
	{
		while(arr[i]<pivot&&i<up)
		i++;
		
		while(arr[j]>pivot)
		j--;
		if(i<j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;j--;
		}
		else
		i++;
		
	}
	arr[low]=arr[j];
	arr[j]=pivot;
	return j;
}

void main()
{
	int array[100],n,i,kth;
	printf("\n\tEnter the # of elements:");
	scanf("%d",&n);
	
	printf("\n\tEnter the elements one by one:");
	for(i=0;i<n;i++)
	scanf("%d",&array[i]);
	
	quick_sort(array,0,n-1);

	printf("\n\nSorted array is\n");
	
	
	for(i=0;i<n;i++)
	printf("%d ",array[i]);
	
	
}

