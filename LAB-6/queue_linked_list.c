//queue implementation using linked list

#include<stdlib.h>
#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *createNode(int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void display(Node *head)
{
    while(head != NULL)
    {
        printf("%d -> ",head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

typedef struct {
    Node *front;
    Node *rear;
}LinkedList;

void enqueue(LinkedList *queue , int value)
{
    Node *newNode = createNode(value);
    if(queue -> front ==NULL)
    {
        queue -> front = newNode;
        queue -> rear = newNode;
    }
    else
    {
        queue -> rear -> next = newNode;
        queue -> rear = newNode;
    }
}

int dequeue(LinkedList *queue)
{
    if(queue -> front == NULL)
    {
        printf("queue is empty : \n");
        return -1;
    }
    int dequeuedvalue = queue -> front -> data;
    Node *temp = queue -> front;
    queue -> front = queue -> front -> next;
    free(temp);
    return dequeuedvalue;
}

void main()
{
    LinkedList queue;
    queue.front = NULL;
    queue.rear = NULL;

    printf("\n queue operations : \n");
    enqueue(&queue,40);
    enqueue(&queue,50);
    enqueue(&queue,60);
    display(queue.front);
    printf("dequeued from queue : %d\n",dequeue(&queue));
    printf("dequeued from queue : %d\n",dequeue(&queue));
    display(queue.front);
}
