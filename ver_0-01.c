#include<stdio.h>

void calc(double a, double b, char c){
    double z=0;
    if(c == '+'){
        z=a+b;
    }else if (c == '-'){
        z=a-b;
    }else if (c == '*'){
        z=a*b;
    }else {
        z=a/b;
    }
    printf("The answer is %lf",z);
}

int main(int argc, char const *argv[])
{
    double aa,bb;
    char cc;
    printf("This is my first calculator program which is only capable of addition, subtraction, muultiplication and division\n");
    scanf("%lf\n%c%lf",&aa,&cc,&bb);
    if (cc== '+' || cc== '-' || cc== '*' || cc=='/'){

        calc(aa,bb,cc);

    }else{
        printf("Invalid symbol or the operation is not supported");
    }

    return 0;
}
