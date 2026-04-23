/*Write a program to create a single linked list of n nodes and perform the following menu
based operations on it using function:
i. Insert a node at the beginning of the SLL
ii. Insert a node at the end of the SLL
iii Insert at a specific position
iv Count nodes
v. Traverse the linked list*/
#include <stdio.h>
#include<stdlib.h>
void create(int);
void insertNodeStart(int);
void insertNodeEnd(int);
void traverse(int);
struct node
{
    int data;
    struct node *next;
};
struct node *link, *head;
void create(int n)
{
    link=(struct node*)(malloc(n*(sizeof(struct node))));
    head=link;
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the data:");
        scanf("%d",&((link+i)->data));
        (link+i)->next=(link+i+1);
         (link+i+1)->next=NULL;
    }

}
void main()
{
    int n;
    printf("Enter total no. of nodes to be created:");
    scanf("%d",&n);
    create(n);
    int ch;
    printf("Operations Available:\n");
    printf("--------------------\n");
    printf("1. Insert a node at the beginning of the SLL\n");
    printf("2. Insert a node at the end of the SLL\n");
    printf("3. Traverse the linked list\n");
    printf("\nEnter Choice:");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:
        insertNodeStart(n);
        break;
        case 2:
        insertNodeEnd(n);
        break;
        case 3:
        traverse(n);
        break;
        default:
        printf("Wrong Choice Entered:");
        break;
    }
}
void insertNodeStart(int n)
{
    struct node *new_node=(struct node*)(malloc(sizeof(struct node)));
    printf("Enter data of new node:");
    scanf("%d",&new_node->data);
    if(head==NULL)
    {
        head=new_node;
        new_node->next=NULL; 
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
    traverse(n);
}
void insertNodeEnd(int n)
{
    struct node *new_node=(struct node*)(malloc(sizeof(struct node)));
    printf("Enter data of new node:");
    scanf("%d",&new_node->data);
    if(head==NULL)
    {
        head=new_node;
        new_node->next=NULL;
    }
    else
    {
        struct node *temp=(struct node*)(malloc(sizeof(struct node)));
        for(temp=head;temp->next!=NULL;temp=temp->next);
        temp->next=new_node;
        new_node->next=NULL;
    }
    traverse(n);
}
void traverse(int n)
{
    struct node *temp=(struct node*)(malloc(sizeof(struct node))) ;
    int ctr=0;
    for(temp=head;temp->next!=NULL;temp=temp->next)
    {
        ctr++;
        printf("Value of Node %d:%d\n",ctr,(int)(temp->data));
    }
}