// DSA
// DA-2
// Dhruv Rajeshkumar Shah
// 21BCE0611

#include <stdio.h>
#include <stdlib.h>

// Doubly linkedlist node
struct node
{
    int value;
    struct node *next;
    struct node *prev;
};

// Function to create a new node
struct node *newNode(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linkedlist
struct node *insertAtBeginning(struct node *head, int value)
{
    struct node *new_node = newNode(value);
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    return head;
}

// Function to insert a new node at the end of the linkedlist
struct node *insertAtEnd(struct node *head, int value)
{
    struct node *new_node = newNode(value);
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    return head;
}

// Function to insert a new node at the given position of the linkedlist
struct node *insertAtPosition(struct node *head, int value, int position)
{
    struct node *new_node = newNode(value);
    if (head == NULL)
    {
        head = new_node;
        return head;
    }
    struct node *temp = head;
    int count = 1;
    while (temp->next != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;
    return head;
}

// Function to delete based on value
struct node *deleteByValue(struct node *head, int value)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->value == value)
    {
        head = head->next;
        head->prev = NULL;
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->value == value)
        {
            temp->next = temp->next->next;
            temp->next->prev = temp;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

// Function to display the linkedlist
void display(struct node *head)
{
    struct node *temp = head;
    printf("\nLinked list: ");
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n\n");
}

// Main function
int main()
{
    struct node *head = NULL;
    int choice = 0;

    while (choice != 6)
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete by value\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            int val1;
            scanf("%d", &val1);
            head = insertAtBeginning(head, val1);
            break;

        case 2:
            printf("Enter the value: ");
            int val2;
            scanf("%d", &val2);
            head = insertAtEnd(head, val2);
            break;

        case 3:
            printf("Enter the value: ");
            int val3, position3;
            scanf("%d", &val3);
            printf("Enter the position: ");
            scanf("%d", &position3);
            head = insertAtPosition(head, val3, position3);
            break;

        case 4:
            printf("Enter the value: ");
            int val4;
            scanf("%d", &val4);
            head = deleteByValue(head, val4);
            break;

        case 5:
            display(head);
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:

            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
