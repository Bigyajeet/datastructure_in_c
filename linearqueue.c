#include<stdio.h>
#include<stdlib.h>
#define MAXQ 100

   int front=0, rear=-1;
   int items[MAXQ] ;
   int isempty();
   int isfull();
   int insert(int);
   int delete();
   int traverse();
   int main()

{
    int x;
    char ch='1';
    printf("\n\tMENU\n************");
    printf("\n 1.INSERT");
    printf("\n 2.DELETE");
    printf("\n 3.Traverse");
    printf("\n 4. QUIT");
    while(ch!='4')
    {
        printf("\n\nEnter your choice from MENU");
        fflush(stdin);
        ch=getchar();
        switch(ch)
        {
            case '1':
            printf("enter the element you want to store in the queue\n");
            scanf("%d",&x);
            insert(x);
            break;


            case '2':
            x=delete();
            printf("enter the element you want to delete is %d in the queue\n",x);
            break;
                 
            case '3':
            traverse();
            break;

            default:
            printf("\n Wrong choice ! Try Again");
        }
    }
}
int isempty()
{
if(rear<front)
return 1;
else
return 0;
}
int isfull()
{
    if(rear==MAXQ-1)
    return 1;
    else 
    return 0;
}
int insert(int x)
{
    if(isfull())
    {
        printf("\n******QUEUE IS OVERLOADED/OVERFLOW*************");

    }
    rear++;
    items[rear]=x;
}

int delete()
{
    int x;
    if(isempty)
    {
        printf("\n******QUEUE IS UNDERFLOW");
    }
x=items[front];
front++;
return x;
}
int traverse()
{
    int i;
    printf("\n elements in the queue are*****\n");
    for(i=0;i<=rear;i++)
    {
        printf("%d\n\t",items[i]);
    }
}
