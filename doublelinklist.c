#include<stdio.h>
#include<stdlib.h>
struct node{
		int val;
		struct node *lp;
		struct node *rp;
		};
		
typedef struct node * dll;
dll head;
dll createnode(int item)
{
	dll temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->val=item;
	temp->lp=NULL;
	temp->rp=NULL;
	return temp;
}

void insert_node_end(int item)
{	dll temp;
	temp=head;	
	while(temp->rp!=NULL)
	temp=temp->rp;
	temp->rp=createnode(item);
	temp->rp->lp=temp;		
}

void display()
{
	dll temp;
	temp=head;

	if(temp==NULL)
	printf("\n\tLinked List is empty");
	else 
	while(temp!=NULL)
	{
		printf("\t%d",temp->val);
		temp=temp->rp;
	}
}

void display_rev()
{
	dll temp;
	temp=head;

	if(temp==NULL)
	printf("\n\tLinked List is empty");
	else 
	while(temp->rp!=NULL)
	temp=temp->rp;
	
	while(temp!=head)
	{
		printf("\t%d",temp->val);
		temp=temp->lp;
	}
	printf("\t%d",temp->val);

}

void delete_node_number(int pos)
{	
	dll p,q;
	int i;
	p=head;
	while(i!=pos&&p!=NULL)
	{	
		q=p;
		p=p->rp;
		i++;
	}
	if(i==pos)
	if(p->rp!=NULL)
	{
		q->rp=q->rp->rp;
		q->rp->lp=q;
	}
	else
	q->rp=NULL;
	else
	printf("\n\tYour entered a invalid position.");
	
	free(p);
}
	

void main()
{
	int ch, item,pos;
	char yes;
	do
	{
	printf("Enter whatever you want to do\n");
	printf("\t\n1.Insertion");
	printf("\t\n2.Delete according to node position ");
	printf("\t\n3.Delete according to node value ");
	printf("\t\n4.Display ");
	printf("\t\n5.Display linked list in reverse order\n\tEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: printf("\n\tEnter the element which u want to enter");
		scanf("%d",&item);
		if(head==NULL)
		head=createnode(item);
		else
		insert_node_end(item);
		break;	
	case 2: printf("\n\tEnter the node number which you want to delete");	
		scanf("%d",&pos);
		delete_node_number(pos);
		break;
	case 3: printf("\n\tEnter the node value which you want to delete");
		break;
	case 4: printf("\n\tItems of Double LL");
		display();
		break;
	case 5: printf("\n\tItems of Double LL");
		display_rev();
		break;
	}
	printf("\n\t Want some more? press 'y' or 'Y': ");
	scanf("%s",&yes);
	}while(yes=='y'||yes=='Y');	
}
