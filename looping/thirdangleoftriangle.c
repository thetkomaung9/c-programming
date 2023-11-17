#include <stdio.h>
int main()
{
    int angle1=0;
    int angle2=0;
    printf("Enter Angle1: ");
    scanf("%d",&angle1);
    printf("Enter Angle2 :");
    scanf("%d",&angle2);
    printf("Show Angle3 :%d",180-(angle1+angle2));


    return 0;
}