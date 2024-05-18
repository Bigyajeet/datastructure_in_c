#include <stdio.h>
#include <stdlib.h>

// Define the Node struct
struct Node {
    int data;
    struct Node* next;
};

// Function to join two linked lists
void joinLists(struct Node** head1, struct Node** head2) {
    // Check if the first list is empty
    if (*head1 == NULL) {
        // If it is, set the head of the first list to the head of the second list
        *head1 = *head2;
        return;
    }

    // Find the last node of the first list
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Update the next pointer of the last node of the first list to point to the head of the second list
    temp->next = *head2;
}

// Function to print the elements of a linked list
void printList(struct Node* head) {
    // Initialize a temporary node to the head of the list
    struct Node* temp = head;

    // If the list is not empty, print the elements
    if (head != NULL) {
        do {
            // Print the data of the current node
            printf("%d ", temp->data);

            // Move to the next node
            temp = temp->next;
        } while (temp != head);
    }
}

// Function to insert a new node at the beginning of a linked list
void push(struct Node** head, int new_data) {
    // Create a new node with the new data value
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // Set the data of the new node to the new value
    new_node->data = new_data;

    // Set the next pointer of the new node to the current head of the list
    new_node->next = (*head);

    // Update the head of the list to point to the new node
    (*head) = new_node;
}

// Main function
int main() {
    // Initialize the heads of the two lists to NULL
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Insert elements in the first list
    push(&head1, 10);
    push(&head1, 20);
    push(&head1, 30);

    // Insert elements in the second list
    push(&head2, 40);
    push(&head2, 50);
    push(&head2, 60);

    // Print the elements of the first list
    printf("First List: ");
    printList(head1);

    // Print the elements of the second list
    printf("\nSecond List: ");
    printList(head2);

    // Join the two lists
    joinLists(&head1, &head2);

    // Print the elements of the joined list
    printf("\nJoined List: ");
    printList(head1);

    return 0;
}