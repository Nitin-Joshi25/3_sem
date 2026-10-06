#include <stdio.h>
#include <stdlib.h>

// Step 2: Define the Node Structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

// Function to insert a node after a specific node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }

    prev_node->next = new_node;
}

// Function to delete a node by key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (*head_ref == temp) {
        *head_ref = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Function to traverse and display the list in forward direction
void traverseForward(struct Node* node) {
    printf("Doubly Linked List (forward): ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to traverse and display the list in backward direction
void traverseBackward(struct Node* node) {
    if (node == NULL) return;

    while (node->next != NULL) {
        node = node->next;
    }

    printf("Doubly Linked List (backward): ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        // Step 4: Create a Menu-Driven Program
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After\n");
        printf("4. Delete a Node\n");
        printf("5. Display List Forward\n");
        printf("6. Display List Backward\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data of the node after which to insert: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                struct Node* temp = head;
                while (temp != NULL && temp->data != key) {
                    temp = temp->next;
                }
                if (temp != NULL) {
                    insertAfter(temp, data);
                } else {
                    printf("Node with data %d not found.\n", key);
                }
                break;
            case 4:
                printf("Enter data of the node to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 5:
                traverseForward(head);
                break;
            case 6:
                traverseBackward(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;  // Return 0 to indicate successful execution
}
