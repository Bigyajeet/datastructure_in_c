#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *create(struct node *start);
void display(struct node *start);
struct node *addtoemptynode(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addatafter(struct node *start,int data,int pos);
struct node *addatbefore(struct node *start,int data, int pos);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);
int main()
{
    int choice,data,pos;
    struct node*start=NULL;
    while(1)
    {
        printf("1.Create List");
        printf("2.Display\n");
        printf("3.Add to empty list\n");
        printf("4.Add at beg\n");
        printf("5.Add at end\n");
        printf("6.Add at after\n");
        printf("7.Add at before\n");
        printf("8.Delete\n");
        printf("9.Reverse\n");
        printf("10.QUIT\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                  start=create(start);
                  break;


            case 2:
                  display(start);
                  break;


            case 3:
                  printf("enter the element you want to insert:");
                  scanf("%d",&data);
                  start=addtoemptynode(start,data);
                  break;

            case 4:
                  printf("enter the element you want to insert at beg:");
                  scanf("%d",&data);
                  start=addatbeg(start,data);
                  break;


            case 5:
                  printf("enter the element you want to insert at end:");
                  scanf("%d",&data);
                  start=addatend(start,data);
                  break;

             case 6:
                  printf("enter the element you want to insert :");
                  scanf("%d",&data);
                  printf("enter the element after you want to insert :");
                  scanf("%d",&pos);

                  start=addatafter(start,data,pos);
                  break;
            
            case 7:
                    
                  printf("enter the element you want to insert :");
                  scanf("%d",&data);
                  printf("enter the element before you want to insert :");
                  scanf("%d",&pos);

                  start=addatbefore(start,data,pos);
                  break;

             case 8:

                       printf("enter the element you want to delete :");
                       scanf("%d",&data);
                      start=del(start,data);
                       break;

            case 9:
                   start=reverse(start);
                   break;

            case 10:
                     exit(1);


            default:
                    printf("wrong choice\n");
         
        }
        
    }
}







