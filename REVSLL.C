#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*link;
    
};
struct node *reverse(struct node *start)
{
    struct node*prev,*ptr,*next;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        ptr=next;
    }
    start=prev;
    return start;
}
