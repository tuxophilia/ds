#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int pi[100];
void cpf(char *,int);
void kmp_matcher(char *p,char *t,int m,int n)
{
	int q,i,time=0;
	cpf(p,m);
	q=0;
	for(i=1;i<=n;i=i+1)
	{
		while(q>0&&p[q+1]!=t[i])
			q=pi[q];
		if(p[q+1]==t[i])
			q=q+1;
		if(q==m)
		{
			cout<<"\nPattern matched"<<++time<<" times\n";
			q=pi[q];
		}
	}
		
}

void cpf(char *p,int m)
{
 	int k=0;
 	int q,i;
 	pi[1]=0;
 	for(q=2;q<=m;q=q+1)
 	{	
 		while(k>0&&p[k+1]!=p[q])
 		k=pi[k];
 		if(p[k+1]==p[q])
 		k=k+1;
 		pi[q]=k;
 	}
}
 	
main()
{
 	int i,m,n,j;
 	char *t,*p,temp;
 	
 	printf("\n\tEnter the size of string: ");
 	cin>>n;
 	printf("\n\tEnter the size of the pattern:");
 	cin>>m;
 	t=new char [n];
 	p=new char [m];

 	printf("\n\tEnter the string: ");
 	for(i=1;i<=n;i=i+1)
 	cin>>t[i];

 	printf("\n\tEnter the pattern: ");
 	for(j=1;j<=m;j=j+1)
	cin>>p[j];

 	kmp_matcher(p,t,m,n);
 
 	return 0;
 }	
