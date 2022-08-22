#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front, rear, size;
    int *array;
};

struct Queue *create_queue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->size = size;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(size * sizeof(int));
    return queue;
}

void enqueue(struct Queue *queue, int item)
{
    if (queue->rear == queue->size - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->array[queue->rear] = item;
}

int dequeue(struct Queue *queue)
{
    if (queue->front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    return item;
}

int is_empty(struct Queue *queue)
{
    if (queue->front == -1)
        return 1;
    return 0;
}

int is_full(struct Queue *queue)
{
    if (queue->rear == queue->size - 1)
        return 1;
    return 0;
}

int peek(struct Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->front];
}

void print_queue(struct Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue- ");
    int i;
    for (i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->array[i]);
    printf("\n");
}

void menu(int opt, struct Queue *queue)
{
    switch (opt)
    {
    case 1:
        printf("Enter the element to be inserted: ");
        int item;
        scanf("%d", &item);
        enqueue(queue, item);
        break;

    case 2:
        printf("Deleted element is %d\n", dequeue(queue));
        break;
    case 3:
        printf("Peek element is %d\n", peek(queue));
        break;
    case 4:
        if (is_empty(queue))
            printf("Queue is empty\n");
        else
            printf("Queue is not empty\n");
        break;
    case 5:
        if (is_full(queue))
            printf("Queue is full\n");
        else
            printf("Queue is not full\n");
        break;
    case 6:
        print_queue(queue);
        break;
    default:
        printf("Invalid choice\n");
    }
}

int main()
{
    int opt = 0;
    struct Queue *queue = create_queue(10);
    while (opt != 7)
    {
        printf("\n");
        printf("Please select one of the following operations: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if queue is Empty\n");
        printf("5. Check if queue is Full\n");
        printf("6. Print Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        menu(opt, queue);
    }
    return 0;
}
