// DA-3
// Dhruv Rajeshkumar Shah
// 21BCE0611

#include <stdio.h>
#include <stdlib.h>

// Swap
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to heapify the tree using min heap
void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Function to implement heap sort for ascending order
void heapSort(int arr[], int n, int sorted_arr[])
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        sorted_arr[n - 1 - i] = arr[0];
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Main
int main()
{
    int arr[] = {12, 11, 13, 5, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sorted_arr[n];

    heapSort(arr, n, sorted_arr);

    printf("Sorted array is \n");
    printArray(sorted_arr, n);
}