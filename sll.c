//single linked list 
#include<stdio.h>
#include<stdlib.h>
int count=0;

struct list
{
    int data;
    struct list *next;
};
struct list*first,*last,*mid;
int create();
int traverse();
int main()
{
    int choice;
    while(1)
    {
        printf("\n*******menu********");
        printf("\n******1.create the node*******");
        printf("\n******2.traverse********");
        
        printf("\n********");
        printf("enter the choice from the menu:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            create();
            break;
            case 2:
            traverse();
            break;

        }    }
}
int create ()
{
    mid=(struct list*)malloc(sizeof(struct list));
    printf("\n\nenter the data in the node\n");
    scanf("%d",&mid->data);
    if(first==NULL)
    {
        mid->next=NULL;
        first=last=mid;

    }
    else{
        last->next=mid;
        last=mid;
    }
    count ++;
}
int traverse()
{
    struct list*temp;
    temp=first;
    while(temp!=NULL)
    {
        printf("\n %d", temp->data);
        temp=temp->next;
    }
}
