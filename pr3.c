#include <stdio.h>
#include <ctype.h>  
#define MAX 50

char stack[MAX];
int top = -1;

void push(char value) {
    stack[++top] = value;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char value) {
    if (value == '(')
        return 0;
    if (value == '+' || value == '-')
        return 1;
    if (value == '*' || value == '/')
        return 2;
    return 0;
}

int main() {
    char exp[50];
    char value;
    int i = 0;

    printf("Enter Expression: ");
    scanf("%s", exp);
    printf("\n");

 
    while (exp[i] != '\0') {
        if (isalnum(exp[i])) {
            printf("%c ", exp[i]);
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            while ((value = pop()) != '(')
                printf("%c ", value);
        } else {
            while (top != -1 && priority(stack[top]) >= priority(exp[i])) {
                printf("%c ", pop());
            }
            push(exp[i]);
        }
        i++;
    }

    
    while (top != -1) {
        printf("%c ", pop());
    }

    return 0;
}
