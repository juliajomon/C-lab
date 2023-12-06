/* JULIA JOMON
    CU-30   */
    
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Element {
    int data;
    int priority;
} Element;

Element Q[MAX];
int front = -1, rear = -1;

void enqueue() {
    Element ele;
    if ((rear + 1) % MAX == front) {
        printf("Queue Full\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &ele.data);

    printf("Enter priority of the inserted element: ");
    scanf("%d", &ele.priority);

    if (front == -1 && rear == -1) {
        front = rear = 0;
        Q[rear] = ele;
    } else {
        rear = (rear + 1) % MAX;
        int i = rear;
        while (i != front && ele.priority < Q[(i - 1 + MAX) % MAX].priority) {
            Q[i] = Q[(i - 1 + MAX) % MAX];
            i = (i - 1 + MAX) % MAX;
        }
        Q[i] = ele;
    }

    printf("Element %d with priority %d was successfully inserted\n", ele.data, ele.priority);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    int del = front;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    printf("Element %d with priority %d successfully deleted out of queue\n", Q[del].data, Q[del].priority);
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue Elements\n");
        int i = front;
        do {
            printf("Data: %d, Priority: %d\n", Q[i].data, Q[i].priority);
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        printf("\n");
    }
}

int main() {
    int choice;

    printf("PRIORITY QUEUE OPERATIONS\n");
    printf("Enter:\n1 to insert\n2 to delete\n3 to print\n4 to exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program Terminated\n");
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}