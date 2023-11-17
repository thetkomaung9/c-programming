#include<stdio.h>
int main()
{
    int number1=0;
    int number2=0;
    printf("please enter a number:");
    scanf("%d %d", &number1, &number2);
    if (number1>number2) {
        printf("Number1 is Maximum number");
    }
    else{
        printf("Number21 is Maximum number");
    }


    return 0;
}