#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void fenqueue(int x) {
    if (rear == MAX -1 && front == 0) {
        printf("Overflow\n");
    } else {
        front = 0;
        rear++;
        queue[rear] =x;
        printf("%d enqueued \n", queue[rear]);
    }
}

void fdequeue() {
    if(front == -1 && rear == -1) {
        printf("underflow");
    } else {
        printf("%d dequeued \n",queue[front]);
        front++;
    }
}

void benqueue(int x) {
    if (rear == MAX -1 && front == 0) {
        printf("Overflow\n");
    } else {
        front--;
        queue[front] =x;
        printf("%d enqueued \n", queue[front]);
    }
}

void bdequeue() {
    if(front == -1 && rear == -1) {
        printf("underflow");
    } else {
        printf("%d dequeued \n",queue[rear]);
        rear--;
    }
}

int main() {
    fenqueue(10);
    fenqueue(20);
    fenqueue(30);
    fenqueue(40);
    fenqueue(50);
    printf("\n");

    fdequeue();
    fdequeue();
    fdequeue();
    printf("\n");

    benqueue(13);
    benqueue(14);
    benqueue(15);
    printf("\n");

    bdequeue();
    bdequeue();
    bdequeue();
    bdequeue();
    bdequeue();
    return 0;
}

