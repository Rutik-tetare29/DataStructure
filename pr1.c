#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the stack

int stack[MAX]; // Array to store the stack elements
int top = -1;   // Variable to keep track of the top of the stack (-1 means stack is empty)

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {  // Check if the stack is full
        printf("Stack Overflow! Cannot push %d\n", value);  // Display overflow message
    } else {
        top++;  // Increment top to make room for the new element
        stack[top] = value;  // Add the element to the stack
        printf("%d pushed to stack.\n", value);  // Confirmation message
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {  // Check if the stack is empty
        printf("Stack Underflow! Cannot pop.\n");  // Display underflow message
        return -1;  // Return error value
    } else {
        printf("%d is popped out\n", stack[top]);  // Display the element being popped
        top--;  // Decrement top to remove the top element
        return 0;  // Return success
    }
}

int main() {
    int i;
    
    // Push some values onto the stack
    push(30);  // Pushing 30 onto the stack
    push(40);  // Pushing 40 onto the stack
    push(50);  // Pushing 50 onto the stack
    push(60);  // Pushing 60 onto the stack
    push(70);  // Pushing 70 onto the stack (stack will be full after this)
    
    // Pop the top two values from the stack
    pop();  // Popping the top element (70)
    pop();  // Popping the top element (60)
    
    // Display the remaining values in the stack
    printf("\nStack values are :\n");
    
    for(i = top; i >= 0; i--)  // Loop from the top to the bottom of the stack
    {
        printf("%d\n", stack[i]);  // Print each element
    }
    
    return 0;
}
