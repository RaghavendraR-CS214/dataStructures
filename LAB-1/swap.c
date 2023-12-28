#include <stdio.h>

void swap(int *, int *);

void main()
{
    int a,b;
    printf("enter the value of a and b : \n");
    scanf("%d%d", &a, &b);
    swap(&a, &b);
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
    printf("the swap values are : %d %d ", *p, *q);
}
