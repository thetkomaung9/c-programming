#include<stdio.h>
int main()
{
    int number=0;
    printf("Emter a Number");
    scanf("%d", &number);
    if (number>0) {
        printf("The Number is Positive\n");
    }else if (number<0) {
        printf("The number is Negative");
    }else{
        printf("The number is zero");
    }


    return 0;
}