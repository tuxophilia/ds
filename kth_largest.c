#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i=1, j=1, *a,n,kth,pos=0,max;
	
	printf("\n\tEnter the size of array : ");
	scanf("%d",&n);
	a=malloc(sizeof(int)*n);
	printf("\n\tEnter the array element one by one : ");
	while(i<=n)
	scanf("%d",&a[i++]);
	
	printf("\n\t Here is the array : ");
	while(j<=n)
	printf("%d ",*(a+j++));
	
	printf("\n\tEnter the Kth position : ");
	scanf("%d",&kth);
	i=1;
	max=*(a+i);
	while(i<=kth)
	{
		j=1;
		max=0;
		while(j<=n)
		{	
			if(max<*(a+j))
			{ max=*(a+j); pos=j;
			}
			j++;
		}
		
		*(a+pos)=0;
		++i;
	}
	
	printf("\n\tThe Kth maximum value where k=%d is %d",kth,max);
		
}
