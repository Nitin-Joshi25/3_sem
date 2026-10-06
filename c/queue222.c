#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
    
};

struct node *head =NULL;
void insert()
{
    struct node *newnode , *temp;
    
    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev =NULL;
    newnode->next =NULL;
    
    if(head == NULL)
    {
        head =newnode;
    }
    
    else
    {
        temp  = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    
}
   
    void display()
    {
        struct node*temp;
        
        temp = head;
        
        while(temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
    }
    
    int main()
    {
        insert();
        insert();
        display();
        return 0;
    }
