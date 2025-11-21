#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *header = NULL;

void insertAtFront(int item)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = header;
    header = newnode;
}

void insertAtLast(int item)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;

    if (header == NULL)
    {
        header = newnode;
        return;
    }

    struct node *ptr = header;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = newnode;
}


void insertAtAny(int item, int key)
{
    if (header == NULL)
    {
        printf("List is empty. Cannot insert after key %d.\n", key);
        return;
    }

    struct node *ptr = header;
    while (ptr != NULL && ptr->data != key)
    {
        ptr = ptr->link;
    }

    if (ptr == NULL)
    {
        printf("Key %d not found.\n", key);
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = ptr->link;
    ptr->link = newnode;
    printf("Inserted %d after %d.\n", item, key);
}


void deleteAtFront()
{
    if (header == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = header;
    header = header->link;
    free(temp);
    printf("Deleted node at front.\n");
}


void deleteAtEnd()
{
    if (header == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (header->link == NULL)
    {
        free(header);
        header = NULL;
        printf("Deleted the only node in the list.\n");
        return;
    }

    struct node *ptr = header;
    struct node *prev = NULL;
    while (ptr->link != NULL)
    {
        prev = ptr;
        ptr = ptr->link;
    }

    prev->link = NULL;
    free(ptr);
    printf("Deleted node at end.\n");
}

void deleteAtAny(int key)
{
    if (header == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *ptr = header;
    struct node *prev = NULL;

    if (header->data == key)
    {
        header = header->link;
        free(ptr);
        printf("Deleted node with key %d.\n", key);
        return;
    }

    while (ptr != NULL && ptr->data != key)
    {
        prev = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL)
    {
        printf("Key %d not found.\n", key);
        return;
    }

    prev->link = ptr->link;
    free(ptr);
    printf("Deleted node with key %d.\n", key);
}


void search(int key)
{
    if (header == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = header;
    int position = 1;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            printf("Key %d found at position %d.\n", key, position);
            return;
        }
        ptr = ptr->link;
        position++;
    }

    printf("Key %d not found in the list.\n", key);
}


void traverseList()
{
    if (header == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = header;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}


int main()
{
    int choice, item, key;

    while (1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at last\n");
        printf("3. Insert after a key\n");
        printf("4. Delete at front\n");
        printf("5. Delete at end\n");
        printf("6. Delete a specific key\n");
        printf("7. Search for a key\n");
        printf("8. Traverse list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &item);
            insertAtFront(item);
            break;

        case 2:
            printf("Enter value to insert at last: ");
            scanf("%d", &item);
            insertAtLast(item);
            break;

        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &item);
            printf("Enter key after which to insert: ");
            scanf("%d", &key);
            insertAtAny(item, key);
            break;

        case 4:
            deleteAtFront();
            break;

        case 5:
            deleteAtEnd();
            break;

        case 6:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteAtAny(key);
            break;

        case 7:
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(key);
            break;

        case 8:
            traverseList();
            break;

        case 9:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

