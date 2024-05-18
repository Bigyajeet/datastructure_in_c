#include<stdio.h>
#include<stdlib.h>
struct Node*head=NULL;
{
int data;
struct Node*next;
};
struct Node* array_to_linked_list(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;

    for (int i = 1; i < n; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node ->data = arr[i];
        new_node ->next = head;
        head = new_node;
    }

    return head;
}