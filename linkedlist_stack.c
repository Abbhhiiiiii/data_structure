#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

struct node 
{
    int data;
    struct node *link;
};

struct node *header = NULL;
int count = 0;

void push(int item) 
{
    if (count >= MAX_SIZE) 
    {
        printf("Stack Overflow! Cannot push %d.\n", item);
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) 
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->data = item;
    newnode->link = header; 
    header = newnode;   
    count++;

    printf("%d pushed to stack.\n", item);
}

void pop()
 {
    if (header == NULL) 
    {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }

    struct node *temp = header;
    int popped_value = temp->data;
    header = header->link;
    free(temp);
    count--;

    printf("%d popped from stack.\n", popped_value);
}

void display()
 {
    if (header == NULL) 
    {
        printf("Stack is empty.\n");
        return;
    }

    struct node *ptr = header;
    printf("Stack elements:\nTop → ");
    while (ptr != NULL) 
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main() 
{
    int choice, item;

    while (1) 
    {
        printf("\n--- Stack using Linked List ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

