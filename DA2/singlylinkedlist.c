// DSA
// DA-2
// Dhruv Rajeshkumar Shah
// 21BCE0611

#include <stdio.h>
#include <stdlib.h>

// Linkedlist node
struct node
{
    int value;
    struct node *next;
};

// Function to create a new node
struct node *newNode(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a new node at the beginning of the linkedlist
struct node *insertAtBeginning(struct node *head, int value)
{
    struct node *new_node = newNode(value);
    new_node->next = head;
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
    return head;
}

// Function to insert a new node at the given position of the linkedlist
struct node *insertAtPosition(struct node *head, int value, int position)
{
    struct node *new_node = newNode(value);
    if (position == 1)
    {
        new_node->next = head;
        head = new_node;
        return head;
    }
    struct node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Function to delete a node for a given value
struct node *deleteNode(struct node *head, int value)
{
    struct node *temp = head;
    if (temp->value == value)
    {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp->next->value != value)
    {
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return head;
}

// Function to delete a node for a given position
struct node *deleteNodeAtPosition(struct node *head, int position)
{
    struct node *temp = head;
    if (position == 1)
    {
        head = temp->next;
        free(temp);
        return head;
    }
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return head;
}

// Function to delete a node at the beginning of the linkedlist
struct node *deleteAtBeginning(struct node *head)
{
    struct node *temp = head;
    head = temp->next;
    free(temp);
    return head;
}

// Function to delete a node at the end of the linkedlist
struct node *deleteAtEnd(struct node *head)
{
    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    struct node *temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
    return head;
}

// Function to search for a node with a given value
int search(struct node *head, int value)
{
    struct node *temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

// Function to reverse the linkedlist
struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// Function to count the number of odd and even numbers in the linkedlist
void countOddEven(struct node *head)
{
    int odd = 0, even = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->value % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
        temp = temp->next;
    }
    printf("Number of odd numbers: %d\n", odd);
    printf("Number of even numbers: %d\n", even);
}

// Function to print the linkedlist
void printList(struct node *head)
{
    struct node *temp = head;
    printf("\nLinkedlist: ");
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n\n");
}

// Menu driven program
int main()
{
    struct node *head = NULL;
    int choice = 0;
    while (choice != 12)
    {
        printf("\nEnter a choice from the following:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete a node\n");
        printf("5. Delete a node at position\n");
        printf("6. Delete at beginning\n");
        printf("7. Delete at end\n");
        printf("8. Search for a node\n");
        printf("9. Reverse the linkedlist\n");
        printf("10. Count the number of odd and even numbers in the linkedlist\n");
        printf("11. Print the linkedlist\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            int val;
            scanf("%d", &val);
            head = insertAtBeginning(head, val);
            break;
        case 2:
            printf("Enter the value to be inserted: ");
            int val2;
            scanf("%d", &val2);
            head = insertAtEnd(head, val2);
            break;
        case 3:
            printf("Enter the value to be inserted: ");
            int val3;
            scanf("%d", &val3);
            printf("Enter the position: ");
            int position3;
            scanf("%d", &position3);
            head = insertAtPosition(head, val3, position3);
            break;
        case 4:
            printf("Enter the value to be deleted: ");
            int val4;
            scanf("%d", &val4);
            head = deleteNode(head, val4);
            break;
        case 5:
            printf("Enter the position: ");
            int position5;
            scanf("%d", &position5);
            head = deleteNodeAtPosition(head, position5);
            break;
        case 6:
            head = deleteAtBeginning(head);
            break;
        case 7:
            head = deleteAtEnd(head);
            break;
        case 8:
            printf("Enter the value to be searched: ");
            int val8;
            scanf("%d", &val8);
            int position8 = search(head, val8);
            if (position8 == -1)
            {
                printf("Value not found\n");
            }
            else
            {
                printf("Value found at position %d\n", position8);
            }
            break;
        case 9:
            head = reverse(head);
            break;
        case 10:
            countOddEven(head);
            break;
        case 11:
            printList(head);
            break;
        case 12:
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}