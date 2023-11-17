#include <stdio.h>
int main()
{
    int number=0;
    printf("Please Enter Number:");
    scanf("%d", &number);
    if(number%2==0) {
        printf("The Number is even");
    }
    else{
            printf("The Number is odd");
        }


    return 0;
}