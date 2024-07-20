#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node* next;
};

int isEmpty(struct Node* top){
    if (top==NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(){
    struct Node* n = (struct Node*)calloc(1,sizeof(struct Node));
    if (n==NULL)
    {
        return 1;
    }
    return 0;
}

void push(struct Node** top, char val){
    if (isFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node* n = (struct Node*)calloc(1,sizeof(struct Node));
        n->data = val;
        n->next = (*top);
        (*top) = n;   
    }
}

char pop(struct Node** top){
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    else
    {
        char ret = (*top)->data;
        struct Node* n = (*top);
        (*top) = (*top)->next;
        free(n);
        return ret;   
    }
}

char stackTop(struct Node* top){
    char c=top->data;
    return c;
}

int isOperand(char ch){
    if ( ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char ch ){
    if ( ch == '*' || ch == '/' || ch == '%' )
    {
        return 2;
    }
    else if ( ch == '+' || ch == '-' )
    {
        return 1;
    }
    return 0;
}

void converter(char* infix, char* postfix, struct Node* top){
    int val=(int)(*infix);
    while ( *infix != '\0' )
    {
        if ( isOperand(*infix) )
        {
            if ( precedence(*infix) > precedence(stackTop(top)))
            {
                push(&top,*infix);
                infix++;
            }
            else
            {
                *postfix = pop(&top);
                postfix++;
            }
        }
        else
        {
            infix++;
        }
    }
    while ( top->next != NULL )    
    {
        *postfix = pop(&top);
        postfix++;
    }
    *postfix = '\0';
}


