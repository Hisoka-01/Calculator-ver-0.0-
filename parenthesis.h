#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int size;
    char* arr;
};

int isEmpty(struct stack* ptr){
    if ( ptr->top == -1 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr, char val){
    ptr->arr[++ptr->top] = val;
}

char pop(struct stack* ptr){
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        char z='\0';
        return z;
    }
    else
    {
        char z= ptr->arr[ptr->top];
        ptr->arr[ptr->top--]='\0';
        return z;
    }
}

int bracektsCheck(char* ptr, struct stack* pit){
    char test;
    while ( *ptr != '\0' )
    {
        if (*ptr=='(' || *ptr=='{' || *ptr== '[' )
        {
            push(pit, *ptr);
            ptr++;
        }
        else if ( *ptr==')' || *ptr=='}' || *ptr== ']' )
        {
            test=pop(pit);
            if ( test == '(' && *ptr != ')' )
            {
                return 0;
            }
            if ( test == '{' && *ptr != '}' )
            {
                return 0;
            }
            if ( test == '[' && *ptr != ']' )
            {
                return 0;
            }
            if ( test == '\0' )
            {
                return 0;
            }
            ptr++;
        }else ptr++;
    }
    if(pit->top!=-1){
        return 0;
    }
    return 1;
}
