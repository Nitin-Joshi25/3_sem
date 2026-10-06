// // C Program for Implementation of Singly Linked List
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element at the beginning of the singly linked list
void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new element at the end of the singly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a new element at a specific position in the singly linked list
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        insertAtFirst(head,data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the first node of the singly linked list
void deleteFromFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete the last node of the singly linked list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at a specific position in the singly linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 0) {
        deleteFromFirst(head);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to print the LinkedList
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver Code
int main() {
    struct Node* head = NULL;
    
    insertAtFirst(&head, 10);
    printf("Linked list after inserting the node:10 at the beginning \n");
    print(head); 
    
    printf("Linked list after inserting the node:20 at the end \n");
    insertAtEnd(&head, 20);
    print(head); 
    
    printf("Linked list after inserting the node:5 at the end \n");
    insertAtEnd(&head, 5);
    print(head); 
    
    printf("Linked list after inserting the node:30 at the end \n");
    insertAtEnd(&head, 30);
    print(head); 
    
    printf("Linked list after inserting the node:15 at position 2 \n");
    insertAtPosition(&head, 15, 2);
    print(head);
    
    printf("Linked list after deleting the first node: \n");
    deleteFromFirst(&head);
    print(head); 
    
    printf("Linked list after deleting the last node: \n");
    deleteFromEnd(&head);
    print(head); 
    
    printf("Linked list after deleting the node at position 1: \n");
    deleteAtPosition(&head, 1);
    print(head); 

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void Insert(int x, List l, Position p)
{
	Position TmpCell;
	TmpCell = (struct Node*) malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("Memory out of space\n");
	else
	{
		TmpCell->e = x;
		TmpCell->next = p->next;
		p->next = TmpCell;
	}
}


int isLast(Position p, List l)
{
	return (p->next == l);
}

Position FindPrevious(int x, List l)
{
	Position p = l;
	while(p->next != l && p->next->e != x)
		p = p->next;
	return p;
}

Position Find(int x, List l)
{
	Position p = l->next;
	while(p != l && p->e != x)
		p = p->next;
	return p;
}

void Delete(int x, List l)
{
	Position p, TmpCell;
	p = FindPrevious(x, l);
	if(!isLast(p, l))
	{
		TmpCell = p->next;
		p->next = TmpCell->next;
		free(TmpCell);
	}
	else
		printf("Element does not exist!!!\n");
}

void Display(List l)
{
	printf("The list element are :: ");
	Position p = l->next;
	while(p != l)
	{
		printf("%d -> ", p->e);
		p = p->next;
	}
}

void main()
{
	int x, pos, ch, i;
	List l, l1;
	l = (struct Node *) malloc(sizeof(struct Node));
	l->next = l;
	List p = l;
	printf("CIRCULAR LINKED LIST IMPLEMENTATION OF LIST ADT\n\n");
	do
	{
		printf("\n\n1. INSERT\t 2. DELETE\t 3. FIND\t 4. PRINT\t 5. QUIT\n\nEnter the choice :: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				p = l;
				printf("Enter the element to be inserted :: ");
				scanf("%d",&x);
				printf("Enter the position of the element :: ");
				scanf("%d",&pos);
				for(i = 1; i < pos; i++)
				{
					p = p->next;
				}
				Insert(x,l,p);
				break;

			case 2:
				p = l;
				printf("Enter the element to be deleted :: ");
				scanf("%d",&x);
				Delete(x,p);
				break;

			case 3:
				p = l;
				printf("Enter the element to be searched :: ");
				scanf("%d",&x);
				p = Find(x,p);
				if(p == l)
					printf("Element does not exist!!!\n");
				else
					printf("Element exist!!!\n");
				break;

			case 4:
				Display(l);
				break;
		}
	}while(ch<5);
	
}

