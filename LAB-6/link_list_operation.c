//linked list operation

#include<stdio.h>
#include<stdlib.h>

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

Node *sortList(Node *head)
{
    if(head == NULL || head -> next == NULL)
        return head;
    int swapped;
    Node *temp;
    Node *end = NULL;
    do
    {
        swapped = 0;
        temp = head;
        while(temp -> next != end)
        {
            if(temp -> data > temp -> next ->data)
            {
                int tempData = temp -> data;
                temp -> data = temp -> next -> data;
                temp -> next -> data =tempData;
                swapped = -1;
            }
            temp = temp -> next;
        }
        end = temp;
    }while(swapped);
    return head;
}

Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *nextNode = NULL;
    while(current != NULL)
    {
        nextNode = current -> next;
        current -> next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

Node *concatLists(Node *list1 , Node *list2)
{
    if(list1 == list2)
        return list2;
    Node *temp = list1;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = list2;
    return list1;
}

void main()
{
    Node *list1 = createNode(3);
    list1 -> next = createNode(1);
    list1 -> next -> next = createNode(4);

    Node *list2 = createNode(2);
    list2 -> next = createNode(5);

    printf("original list 1 : ");
    display(list1);
    printf("original list 2 : ");
    display(list2);

    list1 = sortList(list1);
    printf("sorted list 1 : ");
    display(list1);

    list1 = reverseList(list1);
    printf("reversed list 1 : ");
    display(list1);

    Node *concatenated = concatLists(list1,list2);
    printf("concatenated list : ");
    display(concatenated);
}
