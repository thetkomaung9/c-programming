#include <stdio.h>
int main()
{
    int hour=0;
    int min=0;
    printf("Enter a Hours");
    scanf("%d",&hour);
    printf("Enter a minutes");
    scanf("%d",&min);
    printf("Total min%d",(hour*60)+min);

    return 0;
}