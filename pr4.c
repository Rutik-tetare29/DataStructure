#include <stdio.h>
#define MAX 5 

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if((rear + 1) % MAX == front) { 
        // Check if the queue is full
        printf("Queue is overflow\n");
    } else if(front == -1 && rear == -1) {
        // Queue is empty
        front = rear = 0;
        queue[rear] = x;
        printf("Enqueued: %d\n", x);  // Print message after enqueue
    } else {
        // Normal case
        rear = (rear + 1) % MAX;
        queue[rear] = x;
        printf("Enqueued: %d\n", x);  // Print message after enqueue
    }
}

void dequeue() {
    if(front == -1 && rear == -1) {
        // Check if the queue is empty
        printf("Queue is underflow\n");
    } else if(front == rear) {
        // Only one element left
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1; // Queue becomes empty
    } else {
        // Normal case
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    dequeue();
    dequeue();
    
    return 0;
}
