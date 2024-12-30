#include<stdio.h>
int main()
{
    int number1,number2,remainder;
    printf("Enter your first number:");
    scanf("%d",&number1);

    printf("Enter your second number:");
    scanf("%d",&number2);

    int a = (number1<number2) ? number1 : number2 ;

    for(int i=1 ; i<=a ; i++)
    {
        remainder = a%i;
    }

    printf("\n%d",remainder);
}
