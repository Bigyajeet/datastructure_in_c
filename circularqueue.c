#include<stdio.h>
#include<stdlib.h>
#define Max 10
int q[Max];
int front=-1;
int rear=-1;
void display();
void insert(item);
int del();
int peek();
int isEmpty();
int isFull();
main()
{
    int item;
    int choice;
    while(1)
    {
        printf("***************1.insert\n*************");
        printf("***************2.delete\n*************");
        printf("***************3.peek\n*************");
        printf("***************4.display\n*************");
        printf("***************5.quit\n*************");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case '1':
            // int item;
                    printf("enter the element you want to insert:");
                    scanf("%d",&item);
                    insert(item);
                    break;



            case '2':
            printf("deleted element is %d\n",del());
            break;



            case '3':
                    printf("top most element is %d\n",peek());
                    break;

             case '4':
                   display();
                   break;
        
         case '5':
         exit(1);


                       default:
                       printf("wrong choice!");

        }

    }
}
void insert(int item)
{
    if(isFull())
    {
        printf("queue is overflow\n");
        return;

    }
    if(front==-1)
    if(front=Max-1)
    rear=0;
    else
    rear=rear+1;
    q[rear]=item;

}