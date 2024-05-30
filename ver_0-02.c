#include<stdio.h>
#include<string.h>

void filtration(char* exprsn,int* vv, char* ss){
    while (*exprsn != '\0')
    {
        if (*exprsn=='+' || *exprsn=='-' || *exprsn=='*' || *exprsn=='/' || *exprsn=='(' || *exprsn==')' || *exprsn=='[' || *exprsn==']' || *exprsn=='{' || *exprsn=='}')
        {
            *ss=*exprsn;
        }else if (*exprsn>=48 && *exprsn<=57)
        {
            *vv=*exprsn;
            exprsn++;
        }else continue;
        exprsn++;
    }
}


int main(int argc, char const *argv[])
{
    char input[200];
    int values[50];
    char sign[50];
    scanf("%s",&input);
    printf("%s and the length is ",input);
    filtration(input,values,sign);
    printf("%s and nigga %s",values,sign);
    return 0;
}
