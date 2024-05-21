//This is the first beta version 
//This source code is about the simple operations like addition, subtraction, multiplication and division

#include<stdio.h>

void calc(double a, double b, char c){     //function to perform the artihmetic calculations
    double z=0;
    if(c == '+'){
        z=a+b;
    }else if (c == '-'){
        z=a-b;
    }else if (c == '*'){
        z=a*b;
    }else {                                //end case is division cause i have already added a filtration process in the main
        z=a/b;
    }
    printf("The answer is %lf",z);
}

int main(int argc, char const *argv[])
{
    double aa,bb;                       // variable decleration
    char cc;
    printf("This is my first calculator program which is only capable of addition, subtraction, muultiplication and division\n");
    scanf("%lf\n%c%lf",&aa,&cc,&bb);    //taking in the input
    if (cc== '+' || cc== '-' || cc== '*' || cc=='/'){         //filteration process to check operatior symbol

        calc(aa,bb,cc);                 //calling the function

    }else{
        printf("Invalid symbol or the operation is not supported");      //error message
    }

    return 0;
}

/* In the next version wil try to take the input in single line instead of using multiple lines to lay the
 foundation for taking equatins as input*/

 /* Lesson takeways -
 1. use \n before taking char while taking multiple inputs calling scanf one time to prevent unnecessary errors
 */