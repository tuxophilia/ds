#include<iostream>
using namespace std;

int nodes;
void display(int**);
void enque(int);
int deque();
void dfs(int,int**,int,int*);
void bfs(int,int**,int,int*);

int** construct_adj(int *p,int non,int **adj,int i)
{
	for(int j=1;j<=non;j++)
	*(*(adj+i)+*(p+j))=1;
	
	display(adj);
	
	return adj;
}

void display(int **adj)
{
	for(int i=1;i<=nodes;i++)
	{
	for(int j=1;j<=nodes;j++)
	cout<<" "<<*(*(adj+i)+j);
	cout<<"\n";
	}
	
}

main()
{
 	int non,*p,v,ch;
 	
	cout<<"\n\tEnter the number of nodes in graph: ";
	cin>>nodes;
	
	int **adj = new int*[nodes];
	for(int i=1; i<=nodes; i++)
    	adj[i] = new int [nodes];

	for(int i=1;i<=nodes;i++)
	for(int j=1;j<=nodes;j++)
	*(*(adj+i)+j)=0;
	
	display(adj);
	for(int i=1;i<=nodes;i++)
	{	
		p=new int [nodes];
		cout<<"enter the number of nodes to which node "<<i<<" is connected: ";
		cin>>non;
		cout<<"enter nodes one by one to which node "<<i<<" is connected: ";
		for(int j=1;j<=non;j++)
		cin>>p[j];
		adj=construct_adj(p,non,adj,i);
	}

	cout<<"\n\n\n";	
	display(adj);
	
	while(1)
	{
	int *visited=new int [nodes];
	cout<<"\n\tEnter what u want ";
	cout<<"\n\t1.Depth First Tranversal";
	cout<<"\n\t2.Breadth First Tranversal";
	cout<<"\n\t3.Print Adjacency matrix";
	cout<<"\n\t4.Clear Visited array ";
	cout<<"\n\t5.Exit";
	cout<<"\n\tEnter now : ";
	cin>>ch;
	
		switch(ch)
		{
		
		case 1: cout<<"\n\tEnter the starting node for dfs";
			cin>>v;
			cout<<"DFT with starting node "<<v<<" is : ";
			dfs(v,adj,nodes,visited);
			break;
		case 2: cout<<"\n\tEnter the starting node for dfs";
			cin>>v;
			cout<<"BFT with starting node "<<v<<" is : ";
			bfs(v,adj,nodes,visited);
			break;
		case 3:	display(adj);
			break;
		case 4:	for(int i=1;i<=nodes;i++)
			*(visited+i)=0;
			break;
		case 5: break;
			break;
		default:cout<<"\n\tYou entered a wrong choice!!!!";
		}
	}
	
	return 0;
}

void dfs(int node,int **adj,int no_of_nodes,int *visited)
{
	visited[node]=1;
	cout<<node<<" ";
	for(int i=1;i<=no_of_nodes;i++)
	{
		if(adj[node][i]==1&&visited[i]!=1)
		dfs(i,adj,no_of_nodes,visited);
	}
}

int front=-1,rear=-1,*q=new int [nodes];
void enque(int item)
{
	if(front==-1&&rear==-1)
	{
		front++;
		rear++;
		*(q+front)=item;
	}
	else if(front<rear)
	{
		rear++;
		*(q+rear)=item;
	}
	
}

int deque()
{
	int temp;
	if(front<rear)
	return *(q+front++);
	else if(front==rear)
	{
	temp=*(q+front);
	front=-1;
	rear=-1;
	return temp;
	}
}

void bfs(int node,int **adj,int no_of_nodes,int *visited)
{
	int temp;
	visited[node]=1;
	enque(node);
	while(rear!=-1&&front!=-1)
	{	
		temp=deque();
		cout<<temp;
		for(int i=1;i<=no_of_nodes;i++)
		{
			if(adj[temp][i]==1&&*(visited+i)!=1)
			{
				visited[i]=1;
				enque(i);
			}
		}
	
	}
	
}
