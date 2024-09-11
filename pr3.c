#include <stdio.h>
#include <ctype.h>  // For isalnum() to check if a character is alphanumeric
#define MAX 50  // Define maximum size for stack and expression length

char stack[MAX];  // Stack to hold operators and parentheses
int top = -1;     // Initialize top of the stack to -1 (empty stack)

// Function to push an operator or parenthesis onto the stack
void push(char value) {
    stack[++top] = value;  // Increment top and place the value at the top of the stack
}

// Function to pop the top element from the stack
char pop() {
    if (top == -1)  // If the stack is empty, return -1
        return -1;
    else
        return stack[top--];  // Return the top element and decrement top
}

// Function to determine the priority of an operator
int priority(char value) {
    if (value == '(')  // '(' has the lowest priority, should stay in the stack until ')' is found
        return 0;
    if (value == '+' || value == '-')  // '+' and '-' have the lowest operator priority
        return 1;
    if (value == '*' || value == '/')  // '*' and '/' have higher priority than '+' and '-'
        return 2;
    return 0;
}

int main() {
    char exp[50];  // Array to hold the input infix expression
    char value;    // Variable to hold characters popped from the stack
    int i = 0;     // Index to iterate through the expression

    // Prompt the user to enter the infix expression
    printf("Enter Expression: ");
    scanf("%s", exp);
    printf("\n");

    // Loop through each character in the expression until the end
    while (exp[i] != '\0') {
        // If the character is an operand (number or letter), print it
        if (isalnum(exp[i])) {
            printf("%c ", exp[i]);
        } 
        // If the character is '(', push it onto the stack
        else if (exp[i] == '(') {
            push(exp[i]);
        } 
        // If the character is ')', pop and print operators until '(' is found
        else if (exp[i] == ')') {
            while ((value = pop()) != '(')
                printf("%c ", value);
        } 
        // If the character is an operator
        else {
            // Pop and print operators from the stack while they have higher or equal priority
            while (top != -1 && priority(stack[top]) >= priority(exp[i])) {
                printf("%c ", pop());
            }
            // Push the current operator onto the stack
            push(exp[i]);
        }
        i++;  // Move to the next character in the expression
    }

    // After the entire expression has been processed, pop and print any remaining operators in the stack
    while (top != -1) {
        printf("%c ", pop());
    }

    return 0;
}
