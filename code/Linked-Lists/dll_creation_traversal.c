/*Write a C program to create a double linked list of n nodes and display the linked list by using suitable
user defined functions for create and display operations.*/
#include <stdio.h>
#include<stdlib.h>
void create(int);
void traverse();
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *link;
void create(int n)
{
    link=(struct node*)malloc(n*sizeof(struct node));
    head=link;
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter data %d:",(i+1));
        scanf("%d",&(link+i)->data);
        (link+i)->next=(link+i+1);
    }
    (link+i)->next = NULL;
}
void traverse()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    int ctr=0;
    for(temp=head;temp->next!=NULL;temp=temp->next)
    {
        ctr++;
        printf("Value %d:%d\n",ctr,temp->data);
    }
}
void main()
{
    int n;
    printf("Enter total no. of nodes to be created:");
    scanf("%d",&n);
    create(n);
    traverse();
}