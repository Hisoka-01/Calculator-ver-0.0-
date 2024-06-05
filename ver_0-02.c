#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// add comments

int filtration(char* exprsn, double* vv, char* ss){       //fucntion to seperate values and signs in to two diff arrays
    char* num=(char*)calloc(12,sizeof(char));             //made an array to turn strings into integers 
    char* err_ptr;                                        //pointer for strod function
    int i=0,k=0;                                          //counter for length of number string and length of the array of values
    while (*exprsn !='\0')
    {
        if (*exprsn=='+' || *exprsn=='-' || *exprsn=='*' || *exprsn=='/' || *exprsn=='(' || *exprsn==')' || *exprsn=='[' || *exprsn==']' || *exprsn=='{' || *exprsn=='}')
        {
            *ss=*exprsn;                                   //taking in the sign
            if(i!=0){                                      //chekcing if there is any number in string
            *vv=strtod(num,&err_ptr);                      //converting the string into integer
            i=0;
            free(num);                                     // frred the dynamic memory
            char* num=(char*)calloc(12,sizeof(char));      //using dynamic memory allocation
            vv++;
            k++;
            }
            ss++;
            exprsn++;
        }else if (*exprsn>=48 && *exprsn<=57 || *exprsn=='.')
        {
            num[i]=*exprsn;                                //taking the characters of the integers in a string to turn it into an integer
            exprsn++;
            i++;
        }else if ( *exprsn==' ' &&  i!=0)                 //checking for space in between the numbers or signs
        {
            *vv=strtod(num,&err_ptr);
            i=0;
            free(num);
            char* num=(char*)calloc(12,sizeof(char));
            vv++;
            k++;
            
        }else 
        {
            if ( *exprsn!=' ')
            {
                printf("\nUnknown character detected\n");
            }
            exprsn++;
        }
    }
    exprsn--;
    if (*exprsn>=48 && *exprsn<=57 )                       //checking if a number is left in the string
    {
        *vv=strtod(num,&err_ptr);
        k++;
    }
    free(num);                                             //freed the dynamic memory
    return k;
}


int main(int argc, char const *argv[])
{
    char input[200]="";                                   //variable decleration
    double values[50];
    char sign[50]="";
    scanf("%[^\n]%*c",&input);                            //accepting input from the user
    int len=filtration(input,values,sign);                // using filteration function to seperate the values and signs and also find the length of values array
  
  //testing if function is taking value properly or not

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
