#include <stdio.h>
#include <ctype.h>  // For the isdigit() function to check if a character is a digit

#define MAX 100  // Define the maximum size of the stack and expression length

int stack[MAX];  // Array to store stack elements
int top = -1;    // Variable to keep track of the top of the stack

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {  // Check if the stack is full (overflow condition)
        printf("Stack Overflow\n");
    } else {
        top++;  // Increment top to make room for the new element
        stack[top] = value;  // Add the element to the stack
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {  // Check if the stack is empty (underflow condition)
        printf("Stack Underflow\n");
        return -1;  // Return an invalid value to signal underflow
    } else {
        int value = stack[top];  // Store the top element
        top--;  // Decrement top to remove the top element
        return value;  // Return the popped element
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {  // Loop through each character of the expression
        
        if (isdigit(exp[i])) {  // Check if the current character is a digit
            push(exp[i] - '0');  // Convert the character to an integer and push it onto the stack
        } 
        
        else {  // If the character is an operator
            int val1 = pop();  // Pop the first operand from the stack
            int val2 = pop();  // Pop the second operand from the stack
            
            // Perform the operation based on the current operator and push the result back onto the stack
            switch (exp[i]) {
                case '+': push(val2 + val1); break;  // Addition
                case '-': push(val2 - val1); break;  // Subtraction
                case '*': push(val2 * val1); break;  // Multiplication
                case '/': push(val2 / val1); break;  // Division
            }
        }
    }
    return pop();  // The final result will be the only element left in the stack, so pop and return it
}

int main() {
    char exp[MAX];  // Array to store the input postfix expression
    
    // Ask the user to enter a postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", exp);  // Read the input as a string
    
    // Evaluate the postfix expression and print the result
    int result = evaluatePostfix(exp);
    printf("The result is: %d\n", result);

    return 0;
}
