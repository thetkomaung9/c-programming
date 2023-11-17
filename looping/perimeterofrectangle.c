#include <stdio.h>
int main()
{
    float heigh=0;
    float width=0;
    printf("Enter a heigh of rectangle");
    scanf("%f",&heigh);
    printf("Enter width of rectangle");
    scanf("%f",&width);
    printf("The perimeter of rectangle %.3f",(heigh+width)*2);


    return 0;
}