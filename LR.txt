#include <stdio.h>
#include <stdbool.h>

// Stack size
#define MAX_STACK_SIZE 100

// Stack and top pointer
char stack[MAX_STACK_SIZE];
int top = -1,i;

// Push operation
void push(char c) {
    top++;
    stack[top] = c;
}

// Pop operation
char pop() {
    if (top != -1) {
        char c = stack[top];
        top--;
        return c;
    }
    return '\0'; // Return a default value indicating stack underflow
}

void print() {
    printf("$");
    for(i=0; i<=top; i++) {
        printf("%c", stack[i]);
    }
}

// Parsing function
bool parse(char *input) {
    // Iterate over the input string
    for (int i = 0; input[i] != '\0'; i++) {
        if(input[i]=='i' && input[i+1]=='d') {
            print();
            printf("id");
            printf("\n");
            push('E');
            i++;
            print();
            printf("\n");
        }
        
        if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
            push(input[i]);
            print();
            printf("\n");
        }

    }

    // int n = top;
    char c;
    
    while(top >= 0) {
        c = pop();
        print();
        printf("\n");
        if(c == 'E') {
            continue;
        }
        else {
            if(top!=-1) {
                if(stack[top]!='E') {
                    top++;
                    break;
                }
            } else {
                top++;
                break;
            }
        }
    }
    
    // print();
    // printf("%d\n", top);
    // print();
    return (top == -1);
}



int main() {
    char input[100];

    printf("Enter the expression: ");
    scanf("%s", input);

    bool accepted = parse(input);

    if (accepted)
        printf("\nAccepted\n");
    else
        printf("\nNot Accepted\n");

    return 0;
}
