#include <stdio.h>

void MallocEx(int);
void CallocEx(int);

void main()
{
    int n;

    printf("enter the value of n : \n");
    scanf("%d", &n);
    MallocEx(n);
    CallocEx(n);
}

void MallocEx(int n)
{
    int *ptr;
    int i;
    int arr[n];
    ptr = (int*)malloc(n * sizeof(int));
    for(i=0; i<n; i++)
    {
        ptr[i] = i + 1;
    }
    printf("Malloc dynamic memory allocation \n");
    printf("the elements of the array are : \n");
    for(i=0; i<n; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    printf("\n");
    free(ptr);
}

void CallocEx(int n)
{
    int *ptr;
    int i;
    int arr[n];

    ptr = (int*)calloc(n, sizeof(int));
    for(i=0; i<n; i++)
    {
        ptr[i] = i + 1;
    }
    printf("Calloc dynamic memory allocation \n");
    printf("the elements of the array are : \n");
    for(i=0; i<n; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    printf("\n");
    printf("Realloc dynamic memory allocation \n");
    printf("the elements of the array are : \n");
    n=10;
    ptr = (int*)realloc(ptr, n * sizeof(int));
    for(i=5; i<n; i++)
    {
        ptr[i] = i + 1;
    }
    for(i=0; i<n; i++)
    {
        printf("%d ", ptr[i]);
    }
    free(ptr);
}


