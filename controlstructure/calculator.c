#include "stdio.h"
int main()
{
    int number1=0;
    int number2=0;
    char charactor;
    printf("Enter The Number:");
    scanf("%d %d", &number1, &number2);
    printf("Enter The Operator:");
    scanf(" %c", &charactor);

    switch (charactor) {
        case '+':
            printf("%d",number1+number2);
            break;
        case '-':
            printf("%d",number1-number2);
            break;
        case '*':
            printf("%d",number1*number2);
            break;
        case '/':
            printf("%d",number1/number2);
            break;
        default:
            printf("You have error:");




    }


    return 0;
}
