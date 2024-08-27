#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;


void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    } else {
        printf("%d is poped out\n",stack[top]);
        top--;
        return 0;
    }
}

int main() {
    int i;
    
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    pop();
    pop();
    printf("\nStack values are :");
    
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
    
    return 0;
}