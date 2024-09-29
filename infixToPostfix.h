void converter(char* infix, char* postfix, struct Node* top) {
    while (*infix != '\0') {
        if (isOperand(*infix)) {
            while (!isEmpty(top) && precedence(stackTop(top)) >= precedence(*infix)) {
                *postfix = pop(&top);
                postfix++;
            }
            push(&top, *infix);
            infix++;
        } else if (*infix == '(') {
            push(&top, *infix);
            infix++;
        } else if (*infix == ')') {
            while (stackTop(top) != '(') {
                *postfix = pop(&top);
                postfix++;
            }
            pop(&top);  // Pop '('
            infix++;
        } else {
            *postfix = *infix;
            postfix++;
            infix++;
        }
    }
    
    while (!isEmpty(top)) {
        *postfix = pop(&top);
        postfix++;
    }
    *postfix = '\0';
}
