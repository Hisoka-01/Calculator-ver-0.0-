#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// add comments

int filtration(char* exprsn, double* vv, char* ss){
    char* num=(char*)calloc(12,sizeof(char));
    char* err_ptr;
    int i=0,k=0;
    while (*exprsn != '\0')
    {
        if (*exprsn=='+' || *exprsn=='-' || *exprsn=='*' || *exprsn=='/' || *exprsn=='(' || *exprsn==')' || *exprsn=='[' || *exprsn==']' || *exprsn=='{' || *exprsn=='}')
        {
            *ss=*exprsn;
            if(i!=0){
            *vv=strtod(num,&err_ptr);
            i=0;
            free(num);
            char* num=(char*)calloc(12,sizeof(char));
            vv++;
            k++;
            }
            ss++;
            exprsn++;
        }else if (*exprsn>=48 && *exprsn<=57 || *exprsn=='.')
        {
            num[i]=*exprsn;
            exprsn++;
            i++;
        }else printf("\nUnknown character detected\n");
    }
    exprsn--;
    if (*exprsn>=48 && *exprsn<=57 )
    {
        *vv=strtod(num,&err_ptr);
        k++;
    }
    free(num);
    return k;
}


int main(int argc, char const *argv[])
{
    char input[200]="";
    double values[50];
    char sign[50]="";
    scanf("%s",&input);
    int len=filtration(input,values,sign);
    for(int i=0;i<len;i++){
        printf("%f ",values[i]);
    }
    printf("\n Above are the values given and sign length is %d\n",strlen(sign));
        for(int i=0; i<strlen(sign); i++){
        printf("%c ",sign[i]);
    }
    printf("\n Above are the signs given");

    return 0;
}
