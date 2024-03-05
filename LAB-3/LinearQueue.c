#include <stdio.h>
#define MAX 6

int Q[MAX];
int front = -1, rear = -1;

void insert(int element) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        Q[rear] = element;
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    } else {
        printf("Deleted element: %d\n", Q[front]);
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    } else {
        printf("Elements in the queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
