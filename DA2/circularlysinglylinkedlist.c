// DSA
// DA-2
// Dhruv Rajeshkumar Shah
// 21BCE0611

#include <stdio.h>
#include <stdlib.h>

// Circularly linkedlist node
struct node
{
    int value;
    struct node *next;
};

// Function to create a new node for circularly linkedlist
struct node *newNode(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the circularly linkedlist
struct node *insertAtBeginning(struct node *head, int value)
{
    struct node *new_node = newNode(value);
    if (head == NULL)
    {
        head = new_node;
        head->next = head;
        return head;
    }
    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a new node at the end of the circularly linkedlist
struct node *insertAtEnd(struct node *head, int value)
{
    struct node *new_node = newNode(value);
    if (head == NULL)
    {
        head = new_node;
        head->next = head;
        return head;
    }
    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
    return head;
}

// Function to delete a node from the beginning of the circularly linkedlist
struct node *deleteFromBeginning(struct node *head)
{
    if (head == NULL)
    {
        printf("Linkedlist is empty\n");
        return head;
    }
    struct node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    free(head);
    head = temp->next;
    return head;
}

// Function to delete a node from the end of the circularly linkedlist
struct node *deleteFromEnd(struct node *head)
{
    if (head == NULL)
    {
        printf("Linkedlist is empty\n");
        return head;
    }
    struct node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
    return head;
}

// Function to print the circularly linkedlist
void printCircularlyLinkedList(struct node *head)
{
    if (head == NULL)
    {
        printf("Linkedlist is empty\n");
        return;
    }
    struct node *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("%d ", temp->value);
    printf("\n\n");
}

// Main function
int main()
{
    struct node *head = NULL;
    int choice = 0, value;
    while (choice != 6)
    {
        printf("1. Insert at beginning of the circularly linkedlist\n");
        printf("2. Insert at end of the circularly linkedlist\n");
        printf("3. Delete from beginning of the circularly linkedlist\n");
        printf("4. Delete from end of the circularly linkedlist\n");
        printf("5. Print the circularly linkedlist\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            head = insertAtBeginning(head, value);
            break;

        case 2:
            printf("Enter the value: ");
            scanf("%d", &value);
            head = insertAtEnd(head, value);
            break;

        case 3:
            head = deleteFromBeginning(head);
            break;

        case 4:
            head = deleteFromEnd(head);
            break;

        case 5:
            printCircularlyLinkedList(head);
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }

        printf("\n");
    }

    return 0;
}