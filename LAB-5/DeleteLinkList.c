#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
};

void insertAtEnd(struct Node** head,int value)
{

    struct Node* newNode = createNode(value);
    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node* temp = *head;
        while(temp -> next !=NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

//function to delete the first element from the linked list
void deleteFirst(struct Node** head)
{
    if(*head != NULL)
    {
        struct Node* temp = *head;
        *head = (*head) -> next;
        free(temp);
    }
}

//to delete a specified element
void deleteEle(struct Node** head,int value)
{
    struct Node* current  = *head;
    struct Node* prev = NULL;

    while(current != NULL && current -> data!=value)
    {
        prev = current;
        current = current -> next;
    }

    if(current == NULL)
    {
        printf("empty");
    }
    if(prev == NULL)
    {
        *head = current -> next;
    }
    else
    {
        prev -> next = current -> next;
    }
    free(current);
}

//to delete the last element
void deleteLast(struct Node** head)
{
    if(*head == NULL)
    {
        printf("empty");
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while(temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    if(prev == NULL)
    {
        *head = NULL;
    }
    else
    {
        prev -> next = NULL;
    }
    free(temp);
}

//display
void display(struct Node* head)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

//main function
void main()
{
    struct Node* head = NULL;

    insertAtEnd(&head,1);
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);

    printf("initial linked list : ");
    display(head);

    deleteFirst(&head);
    printf("\nAfter deleting the first element : ");
    display(head);

    deleteEle(&head,2);
    printf("\nafter deleting the specified element : ");
    display(head);

    deleteLast(&head);
    printf("\nafter deleting the last element : ");
    display(head);

}
