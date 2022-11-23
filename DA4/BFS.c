// DA-4
// Dhruv Rajeshkumar Shah
// 21BCE0611

#include <stdio.h>
#include <stdlib.h>

// BFS
void BFS(int n, int a[10][10], int source, int visited[10])
{
    int queue[10], front = -1, rear = -1, i, j;
    queue[++rear] = source;
    visited[source] = 1;
    while (front != rear)
    {
        i = queue[++front];
        printf("%c ", i + 64);
        for (j = 1; j <= n; j++)
        {
            if (a[i][j] == 1 && visited[j] == 0)
            {
                queue[++rear] = j;
                visited[j] = 1;
            }
        }
    }
}

int main()
{
    int n, a[10][10], i, j, source, visited[10];
    char source_letter;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: \n");
    printf("    A B C D E F\n");
    printf("   -------------\n");
    for (i = 1; i <= n; i++)
    {
        printf("%c | ", i + 64);
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    getchar();
    printf("Enter the source vertex: ");
    scanf("%c", &source_letter);
    source = (int)source_letter - 64;
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    printf("The BFS traversal is: ");
    BFS(n, a, source, visited);
    return 0;
}