#include <stdio.h>
int main()
{
    int number1=0;
    int number2=0;
    printf("Enter a number1 :");
    scanf("%d", &number1);
    printf("Enter a number2 :");
    scanf("%d",&number2);
    if(number1==number2){
        printf("The number is equal");
    } else{
        printf("The number is not equal");
    }

    return 0;
}
