#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Function prototypes
int precedence(char op);
double apply_op(double a, double b, char op);
double evaluate(char* expr);
int bracketscheck(char* exprsn);
void process_expression(char* exprsn, double* values, char* signs, int* valueCount, int* signCount);

// Function to check matching brackets
int bracketscheck(char *expr) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            stack[++top] = expr[i];  // Push opening brackets
        } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if (top == -1) {
                return 0;  // Unmatched closing bracket
            }
            char last = stack[top--];  // Pop from stack
            if ((expr[i] == ')' && last != '(') ||
                (expr[i] == ']' && last != '[') ||
                (expr[i] == '}' && last != '{')) {
                return 0;  // Mismatched brackets
            }
        }
    }
    return (top == -1);  // If stack is empty, brackets matched
}

// Function to check operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '%') return 3;
    return 0;
}

// Function to apply an operator to two operands
double apply_op(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b != 0) return a / b; 
            else {
                printf("Error: Division by zero\n");
                return 0;
            }
        case '%':
            if ((int)b != 0) return (int)a % (int)b;
            else {
                printf("Error: Modulus by zero\n");
                return 0;
            }
        default: return 0;
    }
}

// Function to process the expression
void process_expression(char* exprsn, double* values, char* signs, int* valueCount, int* signCount) {
    char num[20];
    int i = 0, j = 0;
    int negative_flag = 0;  // To detect negative numbers

    while (*exprsn != '\0') {
        if (isdigit(*exprsn) || *exprsn == '-') {
            if (*exprsn == '-' && (i == 0 || signs[j - 1] == '(' || signs[j - 1] == '[' || signs[j - 1] == '{')) {
                negative_flag = 1; // Mark negative number
                exprsn++;
                continue;
            }
            // Read the number
            while (isdigit(*exprsn) || *exprsn == '.') {
                num[i++] = *exprsn;
                exprsn++;
            }
            num[i] = '\0'; // Null terminate the string
            values[*valueCount] = negative_flag ? -atof(num) : atof(num); // Convert to double
            (*valueCount)++;
            negative_flag = 0; // Reset flag
            i = 0; // Reset num index
        } else if (*exprsn == '+' || *exprsn == '-' || *exprsn == '*' || *exprsn == '/' || *exprsn == '%') {
            while (j > 0 && precedence(signs[j - 1]) >= precedence(*exprsn)) {
                double val2 = values[--(*valueCount)];
                double val1 = values[--(*valueCount)];
                char op = signs[--j];
                values[*valueCount] = apply_op(val1, val2, op); // Apply the operator
                (*valueCount)++;
            }
            signs[j++] = *exprsn; // Push operator onto stack
            exprsn++;
        } else if (*exprsn == '(' || *exprsn == '[' || *exprsn == '{') {
            signs[j++] = *exprsn; // Push bracket onto stack
            exprsn++;
        } else if (*exprsn == ')' || *exprsn == ']' || *exprsn == '}') {
            while (j > 0 && signs[j - 1] != '(' && signs[j - 1] != '[' && signs[j - 1] != '{') {
                double val2 = values[--(*valueCount)];
                double val1 = values[--(*valueCount)];
                char op = signs[--j];
                values[*valueCount] = apply_op(val1, val2, op); // Apply the operator
                (*valueCount)++;
            }
            j--; // Pop the opening bracket
            exprsn++;
        } else {
            exprsn++; // Ignore spaces and unrecognized characters
        }
    }

    while (j > 0) { // Apply remaining operators
        double val2 = values[--(*valueCount)];
        double val1 = values[--(*valueCount)];
        char op = signs[--j];
        values[*valueCount] = apply_op(val1, val2, op); // Apply the operator
        (*valueCount)++;
    }
}

// Function to evaluate the expression
double evaluate(char* expr) {
    double values[MAX];
    char signs[MAX];
    int valueCount = 0, signCount = 0;

    if (!bracketscheck(expr)) {
        printf("Error: Brackets do not match.\n");
        return 0;
    }

    process_expression(expr, values, signs, &valueCount, &signCount);
    return values[0];  // The result will be in the first element
}

// Main function to handle user input and process expression
int main() {
    char expression[MAX];

    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);

    double result = evaluate(expression);
    printf("The result of the expression is: %.2lf\n", result);

    return 0;
}
