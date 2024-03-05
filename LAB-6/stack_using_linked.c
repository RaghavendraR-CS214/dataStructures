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
    Node *top;
}LinkedList;

void push(LinkedList *stack, int value) {
    Node *newNode = createNode(value);
    newNode -> next = stack -> top;
    stack -> top = newNode;
}

int pop(LinkedList *stack) {
    if(stack -> top == NULL) {
        printf("stack is empty \n");
        return -1;
    }
    int poppedValue = stack -> top -> data;
    Node *temp = stack -> top;
    stack -> top = stack -> top -> next;
    free(temp);
    return poppedValue;
}

void main() {
    LinkedList stack;
    stack.top = NULL;
    printf("stack operations : \n");
     push(&stack, 10);
     push(&stack, 20);
     push(&stack, 25);
     push(&stack, 30);
     display(stack.top);
    printf("popped value : %d\n", pop(&stack));
    printf("popped value : %d\n", pop(&stack));
     display(stack.top);
}

