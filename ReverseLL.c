/* JULIA JOMON
    CU-30   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct node {
    char data;
    struct node* next;
} node;

struct Node* front = NULL;
struct Node* rear = NULL;
struct node* top = NULL;

void enqueue(char item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = item;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void push(char item) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = item;
    newnode->next = top;
    top = newnode;
}

void dequeue() {
    char item;
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    if (front == rear) {
        item = front->data;
        front = rear = NULL;
        push(item);
    }
    else {
        struct Node* temp = front;
        item = front->data;
        front = temp->next;
        free(temp);
        push(item);
    }
}

void display() {
    struct node* tem = top;
    if (top == NULL) {
        printf("empty");
    }
    else {
        while (tem != NULL) {
            printf("%c", tem->data);
            tem = tem->next;
        }
    }
}

int main() {
    char rev[100];
    int n;
    printf("enter Word: ");
    scanf("%s", rev);
    n = strlen(rev);
    for (int i = 0; i < n; i++) {
        enqueue(rev[i]);
    }
    for (int i = 0; i < n; i++) {
        dequeue();
    }
    display();
    return 0;
}
