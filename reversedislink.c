#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};
void reversedisplay(struct Node*START)
{
    if(START==NULL)
    return;
    reversedisplay(START->next);
    printf("%d",START->data);

}
int main ()
{
    struct Node*START=NULL;
    int val1;
    printf("enter the data you want to reverse:");
    scanf("%d",&val1);
    reversedisplay(START);
    return 0;
}