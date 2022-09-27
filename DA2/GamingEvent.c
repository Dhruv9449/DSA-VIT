// DSA
// DA-2
// Dhruv Rajeshkumar Shah
// 21BCE0611

#include <stdio.h>
#include <stdlib.h>

// Student struct
struct student
{
    char name[50];
    int regNo;
    int age;
    int phone;
};

// Linked list node
struct node
{
    struct student data;
    struct node *next;
};

// Function to create a new node
struct node *newNode(struct student data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to count number of students with same age
int check_age(struct node *head, int age)
{
    struct node *new_node;
    int count = 0;
    new_node = head;
    while (new_node != NULL)
    {
        if (new_node->data.age == age)
        {
            count++;
        }
        new_node = new_node->next;
    }
    return count;
}

// Function to insert a new node to linkedlist
struct node *insert(struct node *head, struct student data)
{
    if (check_age(head, data.age) >= 5)
    {
        printf("Can't have more than 5 students of same age!\n\n");
        return head;
    }
    struct node *new_node = newNode(data);
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

// Function to delete a not at the beginning of the linkedlist
struct node *delete (struct node *head, int regNo)
{
    if (head == NULL)
    {
        printf("Linkedlist is empty");
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data.regNo == regNo)
        {
            struct node *temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
            return head;
        }
        temp = temp->next;
    }
    printf("Student not found");
    return head;
}

// Function to display the linkedlist
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Linkedlist is empty");
        return;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("Name: %s, ", temp->data.name);
        printf("RegNo: %d, ", temp->data.regNo);
        printf("Age: %d, ", temp->data.age);
        printf("Phone: %d", temp->data.phone);
        temp = temp->next;
        printf("\n");
    }
    printf("\n\n");
}

// Main function
int main()
{
    struct node *head = NULL;
    struct student data;
    int choice = 0;
    while (choice != 4)
    {
        printf("\n1. Insert student details to linkedlist\n");
        printf("2. Delete student details from linkedlist\n");
        printf("3. Display the linkedlist\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter student details: \n");
            printf("Name: ");
            scanf("%s", data.name);
            printf("RegNo: ");
            scanf("%d", &data.regNo);
            printf("Age: ");
            scanf("%d", &data.age);
            printf("Phone: ");
            scanf("%d", &data.phone);
            head = insert(head, data);
            break;
        case 2:
            printf("Enter the regNo of the student to be deleted: ");
            scanf("%d", &data.regNo);
            head = delete (head, data.regNo);
            break;

        case 3:
            display(head);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice");
        }
    }

    return 0;
}