#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to display the linked list
void display(struct Node* Start) {
    // Traverse the list until the end (next becomes NULL)
    while (Start!= NULL) {
        // Print the data of the current node
        printf("%d -> ", Start->data);
        // Move to the next node
        Start = Start->next;
    }
    // After the loop, if the list is not empty, the last printed element will be followed by NULL
    // If the list is empty, this printf statement will not execute
    printf("NULL\n");
}

// Example usage
int main() {
    // Create a new node with data 10
    struct Node* Start ;
    int val1,val2,val;
    printf("enter the  3 data you want to enter\n;");
    scanf("%d%d%d",&val1,&val2,&val);
    Start= (struct Node*) malloc(sizeof(struct Node));
    Start->data = val1;
    Start->next; //= (struct Node*) malloc(sizeof(struct Node));
    Start->next->data = val2;
    Start->next->next;// = (struct Node*) malloc(sizeof(struct Node));
    Start->next->next->data = val;
    Start->next->next->next = NULL;
    // Display the linked list
    display(Start);
    return 0;
}