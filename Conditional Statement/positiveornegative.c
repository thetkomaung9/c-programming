#include <stdio.h>
int main ()
{
    int number=0;
    printf("Enter a Number");
    scanf("%d",&number);
    if(number>=0){
        printf("The Number is positive");
    } else{
        printf("The Number is Negative");
    }


    return 0;
}

