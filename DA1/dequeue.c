#include <stdio.h>
#include <stdlib.h>

struct Dequeue
{
    int front, rear, size;
    int *array;
};

struct Dequeue *create_dequeue(int size)
{
    struct Dequeue *dequeue = (struct Dequeue *)malloc(sizeof(struct Dequeue));
    dequeue->size = size;
    dequeue->front = dequeue->rear = -1;
    dequeue->array = (int *)malloc(size * sizeof(int));
    return dequeue;
}

void enqueue_front(struct Dequeue *dequeue, int item)
{
    if (dequeue->rear == dequeue->size - 1)
    {
        printf("Dequeue Overflow\n");
        return;
    }
    if (dequeue->front == -1)
        dequeue->front = 0;
    dequeue->rear++;
    dequeue->array[dequeue->rear] = item;
}

void enqueue_rear(struct Dequeue *dequeue, int item)
{
    if (dequeue->rear == dequeue->size - 1)
    {
        printf("Dequeue Overflow\n");
        return;
    }
    if (dequeue->front == -1)
        dequeue->front = 0;
    dequeue->rear++;
    dequeue->array[dequeue->rear] = item;
}

int dequeue_front(struct Dequeue *dequeue)
{
    if (dequeue->front == -1)
    {
        printf("Dequeue Underflow\n");
        return -1;
    }
    int item = dequeue->array[dequeue->front];
    dequeue->front++;
    if (dequeue->front > dequeue->rear)
    {
        dequeue->front = dequeue->rear = -1;
    }
    return item;
}

int dequeue_rear(struct Dequeue *dequeue)
{
    if (dequeue->front == -1)
    {
        printf("Dequeue Underflow\n");
        return -1;
    }
    int item = dequeue->array[dequeue->rear];
    dequeue->rear--;
    if (dequeue->front > dequeue->rear)
    {
        dequeue->front = dequeue->rear = -1;
    }
    return item;
}

int is_empty(struct Dequeue *dequeue)
{
    if (dequeue->front == -1)
        return 1;
    return 0;
}

int is_full(struct Dequeue *dequeue)
{
    if (dequeue->rear == dequeue->size - 1)
        return 1;
    return 0;
}

void print_dequeue(struct Dequeue *dequeue)
{
    if (is_empty(dequeue))
    {
        printf("Dequeue is empty\n");
        return;
    }
    int i;
    for (i = dequeue->front; i <= dequeue->rear; i++)
    {
        printf("%d ", dequeue->array[i]);
    }
    printf("\n");
}

int menu(int opt, struct Dequeue *dequeue)
{
    switch (opt)
    {
    case 1:
        printf("Enter the element to be inserted: ");
        int item_front;
        scanf("%d", &item_front);
        enqueue_front(dequeue, item_front);
        break;
    case 2:
        printf("Enter the element to be inserted: ");
        int item_rear;
        scanf("%d", &item_rear);
        enqueue_rear(dequeue, item_rear);
        break;
    case 3:
        printf("The element deleted is %d\n", dequeue_front(dequeue));
        break;
    case 4:
        printf("The element deleted is %d\n", dequeue_rear(dequeue));
        break;
    case 5:
        if (is_empty(dequeue))
            printf("Dequeue is empty\n");
        else
            printf("Dequeue is not empty\n");
        break;
    case 6:
        if (is_full(dequeue))
            printf("Dequeue is full\n");
        else
            printf("Dequeue is not full\n");
        break;
    case 7:
        print_dequeue(dequeue);
        break;
    default:
        printf("Invalid choice\n");
    }
}

int main()
{
    struct Dequeue *dequeue = create_dequeue(10);
    int opt = 0;
    while (opt != 8)
    {
        printf("\n");
        printf("Please select one of the following operations: \n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Check if empty\n");
        printf("6. Check if full\n");
        printf("7. Print dequeue\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        menu(opt, dequeue);
    }
}